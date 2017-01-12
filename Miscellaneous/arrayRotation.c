/*
Karan Chawla
Array Rotation by given size 
*/

#include <stdio.h> 
#include <stdlib.h> 

//function to rotate the given array by "rot" in left
//or right direction
void rotateArray(int *a, int size, int rot)
{
	int b[size];
	for(int i=0; i<size; i++)
	{
		//if rotation in right
		if(rot>0)
			b[i] = a[(i-rot)%size];
		//rotation in left
		else
			b[i] = a[(i-rot)%size];
	}
	for(int i=0; i<size; i++)
	{
		a[i] = b[i];
	}
	return;
}

//utility function to print array
void printArray(int *a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		/* code */
		printf("%d ", a[i]);
	}
	printf("\n");
}

//driver program
int main(void)
{
	int a[] = {1,2,3,4,5};
	int size = sizeof(a)/sizeof(*a);
	printArray(a,size);
	rotateArrayLeft(a,size,2);
	printArray(a,size);

	return 0;
}