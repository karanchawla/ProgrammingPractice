#include <stdio.h>

int main(void){
	int a[] = {2,3,4,5};
	int size = sizeof(a)/sizeof(*a);
	int num = 0;
	int max= -1;
	for (int i=1;i<size;i++){
		if(a[i]>a[i-1]){
			num++;
			max = a[i];
		}
	}
	printf("%d\n",num);
}