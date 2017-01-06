/*
 Karan Chawla
 Algorithm: kth Order Statistic using Merge Sort and Quick Sort
*/

#include <stdio.h> 
#include <stdlib.h>
//O(n logn) method
 
/*void mergeSort(int *A, int size);
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

int kthSmallest(int *A, int k){
	return A[k-1];
}

int main(void){
	int A[] = {12, 3, 5, 7, 19};
	int k = 2;
	int size = sizeof(A)/sizeof(A[0]);
	mergeSort(A,size);
	int ans = kthSmallest(A,k);
	printf("%d\n", ans);
	return 0;
}*/

int partition(int *A, int left, int right, int k);
int kthSmallest(int *A, int left, int right, int k);

int generatePivot(int left, int right){
	int size = right-left; 
	int r = rand()%size;
	return r;

}
int partition(int *A, int left, int right, int k){
	int p = A[generatePivot(left,right) -1];
	int i = left + 1;
	int temp1 = 0;
	int j = left + 1;
	for(j=left+1 ;j < right; j++){
		int temp = 0;
		if (A[j]<p){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		} else continue;
	}
	temp1= p;
	A[left] = A[i-1];
	A[i-1] = temp1;

	return (i-1);
}

int kthSmallest(int *A, int left, int right, int k){

	if (k>0 && k<= right-left +1){
		int pos = partition(A,left,right, k);
	
		if (pos -left == k - 1){
			return A[pos];
		} else if (pos-left > k-1){
			partition(A, left, pos, k);
		} 
		return partition(A, pos + 1, right, (k- pos + left));
	}

}
		


int main(void){
	int A[]= {7, 10, 4, 3, 20, 15};
	int size = sizeof(A)/sizeof(A[0]);
	int k = 4;
	int ans = kthSmallest(A,0,size,k);
	printf("%d\n", ans);
	return 0;
}