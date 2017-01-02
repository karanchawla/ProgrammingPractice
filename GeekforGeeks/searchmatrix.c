#include <stdio.h> 

int binarySearch(int a[], int high, int low, int value){
	while(high>=low){
		int mid = low + (high-low)/2;
		if(value==a[mid]){
			return 1;
		} else if(value>a[mid]){
			low = mid + 1;
		} else if(value < a[mid]){
			high = mid -1;
		} else {
			return 0;
		}
	}
}

int main(){
	int testcases;
	scanf("%d",&testcases);
	int a[900];
	int rows, cols;
	int value;
	int low, high;
	while(testcases--){
		scanf("%d %d",&rows,&cols);
		for(int i=0;i<(rows*cols);i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&value);
		high = rows*cols - 1 ;
		low = 0;
		int x = binarySearch(a,high,low,value);
		printf("%d\n",x);
	}
	
	return 0;
}