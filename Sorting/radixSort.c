/*
 Karan Chawla
 Algorithm: Radix Sort
*/

#include <stdio.h> 

int getMax(int *A, int size){
	int max = A[0];
	for (int i=0;i<size;i++){
		if (A[i]>max){
			max = A[i];
		}
	}
	return max;
}

void countingSort(int *A, int size, int e){
	int output[size];
	int i, count[10] = {0};

	for(int i=0;i<size;i++){
		count[(A[i]/e)%10]++;
	}

	for(int i=1;i<size;i++){
		count[i] += count[i-1];
	}

	for (int i=0;i<size;i++){
		output[count[(A[i]/e)%10 -1]] = A[i];
		count[(A[i]/e)%10]--;
	}

	for (int i=0;i<size;i++){
		A[i] = output[i];
	}
}

void radixSort(int *A, int size){

	int m = getMax(A, size);
	for(int e=1; m/e > 0; e*=10){
		countingSort(A, size, e);
	}
}

void printArray(int *A, int size){
	for (int i=0;i<size;i++){
		printf("%d\n", *(A+i));
	}
}

int main(void){
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    printArray(arr,n);
    return 0;
}