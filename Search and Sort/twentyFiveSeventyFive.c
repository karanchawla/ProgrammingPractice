#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(void){

	int A[] = {1,1,1,0};
	int size = sizeof(A)/sizeof(A[0]);
	srand(time(NULL));
	int r = rand()%size;
	printf("%d\n", r;
	printf("%d\n", A[r-1]);

	return 0;
}