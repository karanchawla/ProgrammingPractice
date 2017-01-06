/*
 Karan Chawla
 Algorithm: Quick Sort
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Time Complexity O(n logn) amortized

int partition(int A[], int l ,int r, int ar_size);
void QuickSort(int A[], int left, int right, int ar_size);

//utility function to print array
void printArray(int *a, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ", a[i]);
	}
}

int partition(int A[], int l, int r, int ar_size){
	int p = A[0];
	int i = l+1;
	int temp1 = 0;
	int j=l+1;
	for(j=l+1;j<r;j++){
		int temp = 0;
		if (A[j]< p){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i+=1;
		}else continue;
	}
	temp1 = p;
	A[l] = A[i-1];
	A[i-1] = temp1;
	return j;
}	

void quickSort(int A[], int left, int right, int ar_size){
	
	int j=0;
   	for(int k=0;k<ar_size;k++) printf("%d ", *(A+k));
	printf("\n");
	if ((right-left)>0){
		j = partition(A,left,right, ar_size);
		quickSort(A, left, j-1, ar_size);
		quickSort(A, j+1, right, ar_size);
        
	}
}

int main(){
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) { 
      scanf("%d", &ar[i]); 
   }
   quickSort(ar,0,ar_size, ar_size);  
   printArray(ar,ar_size);
}