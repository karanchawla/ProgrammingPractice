//Karan Chawla
//Find the index of zero, which if replaced gives the longest subsequence of 1s

#include <stdio.h>
#include <stdlib.h> 

int findIndex(int *a, size_t size)
{
	int index = 0;

	int start = 0; 
	int count = 0; //stores the number of zeros in the current window

	int max_count = 0;
	int max_index = -1;
	int prev_zero_index;



	for( int i = 0; i <size; i++)
	{	
		//if current element is zero update prev_zero_index and inc count
		if( a[i]==0 )
		{
			count++;
			prev_zero_index = i;
		}

		//if we have more than two zeros 
		// remove elements from window till 
		// last zero is found
		if(count==2)
		{
			while(a[start])
			{
				start++;
			}
			start++;

			count--;
		}


		//if current window length greater than prev max
		//update it
		if( i - start + 1 > max_count)
		{
			max_count  = i - start + 1;
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

int main(void)
{
	int arr[] = { 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int index = findIndex(arr, n);
 
    printf("%d\n", index);

	return 0;
}