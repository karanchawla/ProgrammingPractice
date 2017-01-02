#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Do something with the line
        int size = strlen(line);
        int temp[10] = {0};
        int x[size];
    	for (int i=0;i<size;i++){
    		sscanf(line, "%d", &x[i]);   		
        }
        printf("%d\n", x[5]);
        printf("\n");
        for (int i=0;i<10;i++){
        	//printf("%d\n", temp[i]);
			if(temp[i]==1){
			//printf("%d\n", i);
			break;
    		}
		}
	}
    return 0;
}