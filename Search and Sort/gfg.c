#include<stdio.h>
 
int binarysearch(int arr[], int n){
 
	int low = 0;
	int high = n-1;
	int mid, prev, next;
 
	while(low<=high){
 
		mid = (low+high)/2;
		prev = (mid-1);
		next = (mid+1); 
 
		if(arr[mid]<arr[prev] && arr[mid]<arr[next])
			return mid;
		else if(arr[mid] < arr[high]){
			high=mid-1;
		}
		else low=mid+1;
	}
	return 0;
}
int main(){
 
	int testc, n, i, j,arr[500];
	scanf("%d",&testc);
	while(testc--){
 
		scanf("%d",&n);
		//int arr[n];
		for(i = 0; i<n; i++)
			scanf("%d",&arr[i]);
 
		int index;
		if(n == 1)
			index = 0;
		else index = binarysearch(arr, n);
		printf("%d\n",arr[index]);
	}	
}