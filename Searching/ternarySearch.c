/*
 Karan Chawla
 Algorithm: Binary Search
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#ifndef SIZE
#define SIZE 10000
#endif

#ifndef EPS
#define EPS exp(-12)
#endif 
// Time complexity: O(log n) 

int a[SIZE];

//function
double f(double x)
{
	return x*x + x - 1;
}

//Iterative search function 
double ternarySearch(double left, double right)
{
	if (right - left < EPS) return (left+right)/2.0;
    double leftThird = (2.0*left + right)/3.0;
    double rightThird = (left + 2.0*right)/3.0;
    if (f(leftThird) > f(rightThird)) return ternarySearch(leftThird, right);
	else return ternarySearch(left, rightThird);
}

int main(void)
{
	printf("%f\n", ternarySearch(-10,10));
	return 0;
}