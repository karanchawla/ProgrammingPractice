#include <stdio.h>
#include <stdlib.h> 

//Divide and conquer solution to calculate power of x

int power(int x, int y)
{
	int temp = power(x,y/2);

	if(y==0)
		return 1;
	else if(y%2==0)
	{	 
		return temp*temp;
	}
	else 
		return x*temp*temp;
}

int main(void)
{
	int x = 98753;
	int y = 5234;

	printf("%d\n", power(x,y));
	
	return 0;
}
