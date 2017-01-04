#include <stdio.h>

void printArray(int *A, int size){
	for (int i=0;i<size;i++){
		printf("%d\n", *(A+i));
	}
}

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void bubbleSort(int *A, int size){

	for (int i=0;i<size;i++){
		int flag = 0;
		for (int j=0;j<size-i;j++){
			if (A[j+1]<A[j]){
				swap(&A[j],&A[j+1]);
				flag = 1;
			}
		}
			if(flag==0){
			break;
			}
	}
}

int main()
{
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);	
	return 0;
}