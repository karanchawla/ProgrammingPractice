/*
 Karan Chawla
 Algorithm: Sort one array based on the other given array
*/

#include <stdio.h> 
#include <stdlib.h> 

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high-low)/2;  
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        return first(arr, low, (mid -1), x, n);
    }
    return -1;
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void sortAccording(int *a1, int *a2, int m, int n){
	int temp[m], visited[m];
	for(int i=0;i<m;i++){
		temp[i]=a1[i]; 
		visited[i] = 0;
	} 
	
	qsort (temp, sizeof(temp)/sizeof(*temp), sizeof(*temp), comp);
	
	int k=0; //for index of sorted output of a1

	for (int i=0;i<n;i++){
		int f = first(temp, 0, m-1, a2[i], m);

		if(f==-1) continue;

		for(int j=f;(j<m && temp[j]==a2[i]);j++){
			a1[k++] = temp[j];
			visited[j]=1;
		}
	}

	for(int i=0;i<m;i++){
		if(visited[i]==0){
			a1[k++]= temp[i];
		}
	}
}

void printArray(int *a, int size){

	for(int i=0;i<size;i++){
		printf("%d ", a[i]);
	}
}

int main(void){

	int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]);
    sortAccording(A1, A2, m, n);
    printArray(A1,m);
    return 0;
}