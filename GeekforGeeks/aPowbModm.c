#include <stdio.h>
#include <math.h> 
#include <string.h> 

int main(void){
	int t; 
	while (scanf("%d", &t)){
		printf("%d\n", t);
		if(t==42){
			break;
		}
	}

	return 0;
} 