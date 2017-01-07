#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void insertionSort(int *a, int size)
{
	int i, key, j;

	for(i=1;i<size;i++)
	{
		key = a[i];
		j=i-1;

		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

//utility function to swap numbers
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

//utility function to compare numbers
int comp(int a, int b)
{
	if(a>b) return 1;
	else if(a<b) return -1;

	return 0;
}

int main(void)
{
	FILE *file = fopen("median.txt","r");
	char line[1024];
	int num[10000];
	int median;
	int sum = 0;
	int i=0;

	 while (fgets(line, 1024, file))
	 {
	 	num[i] = atoi(line);
		insertionSort(num,i+1);
		int k = i+1;

		if(k%2==0)
		{
			median = num[k/2-1];
			sum += median;
			//printf("%d\n",num[k/2]);
		}else
		{
			median = num[(k+1)/2-1];
			sum += median;
			//printf("%d\n",num[(k+1)/2]);
		}

		i++;
		//printf("%d\n",median );
	 }

	printf("%d ",sum%10000);
	
	return 0;
}