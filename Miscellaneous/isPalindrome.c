/*
Karan Chawla
Check for a number palindrome without using string 
methods. 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/////////////////////////////////////////////////////////////////////
//Utility functions for Dynamic Arrays
typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

///////////////////////////////////////////////////////////////////////

//function to check if the given number is a palindrome or not
void isPalindrome(Array *num, size_t size)
{
	int flag = 0;
	
	for( int i=0 ; i<(size+1)/2 ; i++)
	{

		if(num->array[i]==num->array[size-i-1])
		{
			flag = 1;
		}
		else
		{
			flag =0;
			break;
		} 
	}

	if (flag) printf("True\n");
	else printf("False\n");
}


//Driver Function
int main(void)
{
	//Test Case 1
	//int num = 1112111;

	//Test Case 2
	//int num = 1;

	//Test Case 3
	//int num = 59112;

	//Test Case 4
	//int num = 1234554321;

	//Test Case 5
	//int num = 22;

	//Test Case 6
	//int num = 1010100101;

	//Test Case 7
	int num = 1010110101;

	Array a ;
	//Since input can be atleast one digit
	//allocate a space of 1
	initArray(&a,1);

	int i = 0;

	while(num)
	{
		insertArray(&a,num%10);
		num/=10;
	}

	
	size_t size = a.used;

	isPalindrome(&a,size);

	freeArray(&a);

	return 0;
}