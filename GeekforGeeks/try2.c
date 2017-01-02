#include <stdio.h> 
#include <stdlib.h>
//O(n logn) method

void mergeSort(int *A, int size);
void merge(int *A, int *L, int left, int *R, int right);
int kthSmallest(int *A, int k);

void merge(int *A, int *L, int left, int *R, int right){
	int i,j,k;
	i=0; j=0; k=0;
	while(i<left && j<right){
		if(L[i]<R[j]){
			A[k] = L[i];
			k++; i++;
		} else {
			A[k] = R[j];
			k++; j++;
		}
	}
	while (i<left) A[k++]=L[i++];
	while (j<right) A[k++] = R[j++];
}
void mergeSort(int *A, int size){
	int mid, i, *L, *R;
	if (size<2) return;
	mid = size/2;
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((size-mid)*sizeof(int));
	for(i=0;i<mid;i++) L[i] = A[i];
	for(i=mid;i<size;i++) R[i-mid] = A[i];
	mergeSort(L,mid);
	mergeSort(R,size-mid);
	merge(A,L,mid,R,size-mid);
	free(L);
	free(R); 
}

int main(void){
	int A[] = {12, 3, 5, 7, 19};
	int size = sizeof(A)/sizeof(A[0]);
	int temp[size];
	for(int i=0;i<size;i++){
		temp[i] = A[i];
	}
	mergeSort(A,size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(temp[i]==A[j]){
				printf("%d ", j);
				break;		
			}
		}	
	}
	
	return 0;
}