/*
 Karan Chawla
 Algorithm: Search floor of a given number in an array
*/
#include <stdio.h> 

//Time Complexity O(log n)
 
int searchFloor(int a[], int high, int low, int value){
	if (value>=a[high]){
		return high;
	}
	int mid;
	while(high>=low){
		mid = low + (high-low)/2;
		if (value<a[0]){
			return -1;
		} else if(value==a[mid]){
			return a[mid];
		} else if(value>a[mid]){
			low = mid + 1;
		} else if(value < a[mid]){
			high = mid -1;
		} 
	}
	if (value>a[mid]){
		return a[mid];
	} else if (value<a[mid]){
		return a[mid-1];
	}
}


//Driver function
int main(){

	int size, x;
	int a[] = {1,2,8,10,11,12,19};
	size = 7;
	x = 15;
	int high = size-1;
	int low = 0;
	int out = linearFloor(a,high,low,x);
	printf("%d\n",out);
	return 0;
}