/*
Karan Chawla
Algorithm: Given an array check for a pair in array for sum x
Time Complexity: O(nlog(n)) amortized
Auxillary Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

//utlitiy function used by qsort
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int checkForPair(int *a, int size, int givenSum)
{
	int i = 0;
	int j = size-1;
	for(int i=0;i<size-1;)
	{
		if(a[i]+a[j]==givenSum)
		{
			return 1;
		}

		if(a[i]+a[j] < givenSum)
			i++;
		else
			j--;
	}
	return 0;
}

int main(void)
{
	int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int size = sizeof(A)/sizeof(*A);
    //sort the array
    qsort(A,size,sizeof(*A),comp);
    int ans = checkForPair(A,size,n);
    if(ans)
    	printf("Pair exists\n");
    else
    	printf("Pair doesn't exist\n");
    return 0;
}