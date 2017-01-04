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

int main(void){
	int a[] = {1,11,53,455,566,900,910,930};
	int size =sizeof(a)/sizeof(a[0]);
	int low, mid,high;
	low = 0;
	high = size-1;
	int value = 910;
	int ans = binarySearch(a,high,low,value);
	printf("%d\n", ans);
} 

