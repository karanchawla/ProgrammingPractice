// Sample code to read in test cases:
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    FILE *file = fopen("test.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Do something with the line
    	int x = atoi(line);
    	//printf("%d\n", x);
    	if(x%2==0){
    		printf("1\n");
    	}else {
    		printf("0\n");
    	}	
}
    return 0;
}
