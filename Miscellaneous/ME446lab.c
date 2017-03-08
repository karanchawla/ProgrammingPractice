#include <tistdtypes.h>
#include <coecsl.h>
#include "user_includes.h"
#include "math.h"

// These two offsets are only used in the main file user_CRSRobot.c  You just need to create them here and find the correct offset and then these offset will adjust the encoder readings
float offset_Enc2_rad = -0.3834;
float offset_Enc3_rad = 0.2756;


// Your global varialbes.  

long mycount = 0;
long newCount = 0;

#pragma DATA_SECTION(whattoprint, ".my_vars")
float whattoprint = 0.0;

#pragma DATA_SECTION(theta1array, ".my_arrs")
float theta1array[100];

#pragma DATA_SECTION(theta2array, ".my_arrs")
float theta2array[100];

long arrayindex = 0;

float printtheta1motor = 0;
float printtheta2motor = 0;
float printtheta3motor = 0;

// Assign these float to the values you would like to plot in Simulink
float Simulink_PlotVar1 = 0;
float Simulink_PlotVar2 = 0;
float Simulink_PlotVar3 = 0;
float Simulink_PlotVar4 = 0;

//positions in the global coordinate frame
float x;
float y;
float z;
float thetas[3];

//PID Gains structure definition
typedef struct PID
{
	float Kp;
	float Kd;
	float Ki;
}PID;

//wrapping the variables associated with the filter in a struc
typedef struct vel_filter
{
	float theta_old;
	float omega_old1;
	float omega_old2;
	float omega;
}vel_filter;

//Inverse kinematics for the robot arm
void invKinematics(float x, float y, float z, float* thetas)
{
	float z0 = z - 10;
	float d = (x*x + y*y + z0*z0 - 200)/200;
	float q1inv = atan2(y, x);
	float q3inv =  atan2(sqrt(1 - d*d), d);
	float q2inv = -atan2(z0, sqrt(x * x + y * y) ) - atan2(10 * sin(q3inv) , 10 + 10 * cos(q3inv));

	float q1 = q1inv;
	float q2 = q2inv + PI/2;
	float q3 = q3inv + q2 - PI/2;

	thetas[0] = q1;
	thetas[1] = q2;
	thetas[2] = q3;
}

//Global theta desired values
float theta1motor_des = 0.0;
float theta2motor_des = 0.0;
float theta3motor_des = 0.0;

//Declaration of PID objects for 3 joints
PID ctrl1 = {60,2,0.3};
PID ctrl2 = {60,1,0.3};
PID ctrl3 = {60,1,0.3};

//Initializing velocity struct
vel_filter filter1 = {0,0,0,0};
vel_filter filter2= {0,0,0,0};
vel_filter filter3= {0,0,0,0};

//Creating a structure for the errors
typedef struct Error
{
	float prev_error;
	float curr_error;
	float total_error;
}Error;

//Initializing the error values for three joints
Error jointError[3];
for (int i = 0; i < 3; ++i)
{
	jointError[i].prev_error = 0;
	jointError[i].curr_error = 0;
	jointError[i].total_error = 0;
}

//For the trajectory
float DesiredValue[3] = {0,0,0};

//Feedforward constants
float J1 = 0.0167;
float J2 = 0.03;
float J3 = 0.0128;

//Standard implementation for the velocity filtering algorithm given in the lab manual
static inline float velocityFilter(float thetamotor, vel_filter* vel_filter)
{
	vel_filter->omega = (thetamotor - vel_filter->theta_old)/0.001;
	vel_filter->omega = (vel_filter->omega + vel_filter->omega_old1 + vel_filter->omega_old2)/3.0;

	vel_filter->theta_old = thetamotor;

	vel_filter->omega_old2 = vel_filter->omega_old1;
	vel_filter->omega_old1 = vel_filter->omega;

	return vel_filter->omega;
}

//Function genrates theta, thetadot and thetaddot for the trajectory*
void cubicSplineTest(float t)
{
	float Coeff1[4] = {0.0, 0.0, 1.5, -1.0};
	float Coeff2[4] = {-2.0, 6.0, -4.5, 1.0};

	if(t < 1000)
	{
		t=t/1000;
		
		for (int i = 0; i < 3; ++i)
		{
			td[i] = Coeff1[0]+Coeff1[1]*t+Coeff1[2]*t*t+Coeff1[3]*t*t*t;
			tdDot[i] = Coeff1[1]+2*Coeff1[2]*t+3*Coeff1[3]*t*t;
			tdDoubleDot[i] = 2*Coeff1[2]+6*Coeff1[3]*t;
		}

	}
	if( t >=1000 && t <= 2000)
	{
		t= t/1000;
		for (int i = 0; i < 3; ++i)
		{
			td[i] = Coeff2[0]+Coeff2[1]*t+Coeff2[2]*t*t+Coeff2[3]*t*t*t;
			tdDot[i] = Coeff2[1]+2*Coeff2[2]*t+3*Coeff2[3]*t*t;
			tdDoubleDot[i] = 2*Coeff2[2]+6*Coeff2[3]*t;
		}
	}
	if( t > 2000 )
	{
		for (int i = 0; i < 3; ++i)
		{
			td[i] = 0;
			tdDot[i] = 0;
			tdDoubleDot[i] = 0;
		}
	}
}

//Inverse kinematics for the arm in 2D plane
void InverseK(float x, float y, float z, float L, float *td1, float* td2, float* td3)
{
	*td1 = atan2(y,x);

	float R = sqrt(x*x + y*y);
	float d = sqrt(R*R + z*z);
	float beta = atan2(z,R);
	float gamma = atan2(sqrt(L*L - d*d/4),d/2);

	*td2 = PI/2 - gamma - beta;
	*td3 = gamma - beta;
}

float td[3] = {0,0,0}; //variables for theta desired at t_{n+1}
float td0[3] = {0,0,0}; //variables for theta desired at t_{n-1}
float tdn[3] = {0,0,0}; //variables for theta desired at t_{n}
float tdDot[3] = {0,0,0}; //variables for thetaDot desired at t_{n}
float tdDoubleDot[3] = {0,0,0}; //variables for thetaDoubleDot desired at t_{n}

float xr0 = 10; //x axis offset
float y0 = 0; //y axis offset
float zr0 = 8; //z axis offset
float Rr0 = 3; //Set radius for trajectory
float period = 4; //set time period for the trajectory as 4 sec


/*
Function trajectoryGenerator takes in mycount as its input 
Updates theta, thetaDot and thetaDoubleDot based on trajectory values
*/
static inline void trajectoryGenerator(float t, char c)
{
	float time = 0.001*t; //input t is mycount 1000*mycount = 1 sec
	float phi = 2*PI*time/period; //constant definition
	float delta = 0.005; //Sampling time period

	if(c=='c') //For circular trajectory
	{
		if( time <= 100*period) //run the trajectory a hundred times
		{
			//Sample trajectory at T_n
			x = xr0 + Rr0 * sin(phi);
			y = y0;
			z = zr0 + Rr0 * cos(phi);

			//Sample trajectory at T_{n-1}
			float x0 = xr0 + Rr0* sin(phi - PI*delta*2/period);
			y0 = 0;
			float z0 = zr0 + Rr0*cos(phi - PI*delta*2/period);

			//Sample trajectory at T_{n+1}
			float x2 = xr0 + Rr0* sin(phi + PI*delta*2/period);
			float y2 = 0;
			float z2 = zr0 + Rr0*cos(phi + PI*delta*2/period);

			//Get desired theta values using the inverse kinematics of the robot arm
			InverseK(x, y, z, 10.0, tdn[0], tdn[1], tdn[2]);
			InverseK(x0, y0, z0, 10.0, td0[0], td0[1], td0[2]);
			InverseK(x2, y2, z2, 10.0, td[0], td[1], td[2]);

			//Calculate thetaDot and thetaDoubleDot using discretization of derivative
			//and double derivative
			for (int i = 0; i < 3; ++i)
			{
				tdDot[i] = (td[i]-td0[i])/delta/2;
				tdDoubleDot[i] = (td[i] - 2*tdn[i] + td0[i])/(delta*delta);
			}
		}
	}
	else if(c=='i') //For infinity trajectory
	{
		if( time <= 100*period)
		{
			//Sample trajectory at T_n
			x = xr0 + Rr0 * scale *cos(phi);
			y = 0;
			z = zr0 + Rr0 * scale*sin(2*phi)/2;

			//Sample trajectory at T_{n-1}
			float x0 = xr0 + Rr0 * scale*cos(phi - PI*delta*2/period);
			y0 = 0;
			float z0 = zr0 + Rr0 *scale*sin(2*(phi - PI*delta*2/period))/2;

			//Sample trajectory at T_{n+1}
			float x2 = xr0 + Rr0*scale*cos(phi + PI*delta*2/period);
			float y2 = 0;
			float z2 = zr0 + Rr0*scale*sin(2*(phi + PI*delta*2/period))/2;

			//Get desired theta values using the inverse kinematics of the robot arm
			InverseK(x, y, z, 10.0, tdn[0], tdn[1], tdn[2]);
			InverseK(x0, y0, z0, 10.0, td0[0], td0[1], td0[2]);
			InverseK(x2, y2, z2, 10.0, td[0], td[1], td[2]);

			//Calculate thetaDot and thetaDoubleDot using discretization of derivative
			//and double derivative
			for (int i = 0; i < 3; ++i)
			{
				tdDot[i] = (td[i]-td0[i])/delta/2;
				tdDoubleDot[i] = (td[i] - 2*tdn[i] + td0[i])/(delta*delta);
			}			
		}
	}
	else //Otherwise throw an error
		printf("Trajectory Name unrecognized\n");
}

//Combined function for controlling all the joints
//Uses feedforward and PID controller
//Returns the torque output which is sent to each motor 
static inline float Controller(char joint , float thetamotor, float thetamotor_dot, PID *ctrl)
{
	//Use the PID controller close to desired angles
	float tau = 0;
	float int_error = 0;

	if(fabs(*curr_error) < 0.2)
	{
		//To Do:
		//Add a switch case such that the feedforward can be turned on and off 
		//For joint 1
		if(joint=='1')
		{
			//Integration error
			jointError[0].curr_error = (td0[0] - thetamotor);
			jointError[0].total_error = jointError[0].total_error + (jointError[0].prev_error + jointError[0].curr_error)*.001/2;
			int_error = jointError[0].total_error;
			tau = J1*tdDoubleDot[0] + ctrl->Kp*(td0[0]-thetamotor) + ctrl->Kd*(tdDot[0] - thetamotor_dot) + ctrl->Ki*(int_error); 
			jointError[0].prev_error = jointError[0].curr_error;
		}
		//For joint 2
		else if(joint=='2')
		{
			//Integration error
			jointError[1].curr_error = (td0[1] - thetamotor);
			jointError[1].total_error = jointError[1].total_error + (jointError[1].prev_error + jointError[1].curr_error)*.001/2;
			int_error = jointError[1].total_error;
			tau = J1*tdDoubleDot[1] + ctrl->Kp*(td0[1]-thetamotor) + ctrl->Kd*(tdDot[1] - thetamotor_dot) + ctrl->Ki*(int_error); 
			jointError[1].prev_error = jointError[1].curr_error;
		}
		//For joint 3
		else if(joint=='3')
		{
			//Integration error
			jointError[2].curr_error = (td0[2] - thetamotor);
			jointError[2].total_error = jointError[2].total_error + (jointError[2].prev_error + jointError[2].curr_error)*.001/2;
			int_error = jointError[2].total_error;
			tau = J1*tdDoubleDot[2] + ctrl->Kp*(td0[2]-thetamotor) + ctrl->Kd*(tdDot[2] - thetamotor_dot) + ctrl->Ki*(int_error); 
			jointError[2].prev_error = jointError[2].curr_error;
		}
	}
	else
	{
		//Use PD controller for everything else
		*total_error = 0;
		if(joint=='1')
		{
			tau = J1*tdDoubleDot[0] + ctrl->Kp*(td0[0]-thetamotor) + ctrl->Kd*(tdDot[0] - thetamotor_dot);
		}
		else if(joint=='2')
		{
			tau = J2*tdDoubleDot[1] + ctrl->Kp*(td0[1]-thetamotor) + ctrl->Kd*(tdDot[1] - thetamotor_dot);
		}
		else if(joint=='3')
		{
			tau = J3*tdDoubleDot[2] + ctrl->Kp*(td0[2]-thetamotor) + ctrl->Kd*(tdDot[2] - thetamotor_dot);
		}
	}

	//Saturate output torque
	if(tau > 5)
		return 5.0;
	else if(tau < -5)
		return -5.0;
	else
		return tau;
}


// This function is called every 1 ms
void lab(float theta1motor,float theta2motor,float theta3motor,float *tau1,float *tau2,float *tau3, int error) {

	//Use the filter to determine joint velocity from encoder values
	float theta1motor_dot = velocityFilter(theta1motor, &filter1);
	float theta2motor_dot = velocityFilter(theta2motor, &filter2);
	float theta3motor_dot = velocityFilter(theta3motor, &filter3);

	trajectoryGenerator(mycount,'i');

	//Motor torque limitation(Max: 5 Min: -5)

	//Control input for the joints
	*tau1 = Controller('1',theta1motor, theta1motor_dot, &ctrl1);
	*tau2 = Controller('2',theta2motor, theta2motor_dot, &ctrl2);
	*tau3 = Controller('3',theta3motor, theta3motor_dot, &ctrl3);

	// save past states
	if ((mycount%50)==0) {

		theta1array[arrayindex] = theta1motor;
		theta2array[arrayindex] = theta2motor;
		if (arrayindex >= 100) {
			arrayindex = 0;
		} else {
			arrayindex++;
		}

	}

	if ((mycount%1000)==0) {
		printtheta1motor = theta1motor;
		printtheta2motor = theta2motor;
		printtheta3motor = theta3motor;
		SWI_post(&SWI_printf); //Using a SWI to fix SPI issue from sending too many floats.
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1; // Blink LED on Control Card
		GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1; // Blink LED on Emergency Stop Box
	}

	Simulink_PlotVar1 = td2;
	Simulink_PlotVar2 = theta2motor;
	Simulink_PlotVar3 = td3;
	Simulink_PlotVar4 = theta3motor;

	mycount++;
	newCount++;

	// float q1 = theta1motor;
	// float q2 = theta2motor;
	// float q3 = theta3motor;
	// x = 20 * cos(q1) * sin( PI/4 + q2/2 - q3/2) * sin( PI/4 + q2/2 + q3/2);
	// y = 20 * sin(q1) * sin(PI/4 + q2/2 - q3/2) * sin(PI/4 + q2/2 + q3/2);
	// z = 10 * (1 + cos(q2) - sin(q3));
	// invKinematics(x,y,z,thetas);

}

void printing(void){
	serial_printf(&SerialA, "%.2f %.2f %.2f :: %.2f %.2f %.2f :: %.2f %.2f %.2f \n\r",printtheta1motor*180/PI,printtheta2motor*180/PI,printtheta3motor*180/PI,x,y,z,thetas[0]*180/PI,thetas[1]*180/PI,thetas[2]*180/PI);
}

