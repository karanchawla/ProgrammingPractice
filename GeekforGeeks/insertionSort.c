#include <stdio.h> 

void printArray(int *A, int size){
	for (int i=0;i<size;i++){
		printf("%d ", *(A+i));
	}
}

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;   }
}

void moveArray(int *A, int size){
	int j=0;
	int B[size];
	while(j!=size-1){
		B[j+1] = A[j];
		j++;
	}
	B[0] = A[size-1];
	for(int i=0;i<size;i++){
		A[i] = B[i];
	}
}


int main()
{
	//int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
   	//insertionSort(arr,n);
    moveArray(arr,n);
    printArray(arr,n);	
	return 0;
}