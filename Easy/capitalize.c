// Sample code to read in test cases:
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
int main() {
    FILE *file = fopen("test.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Do something with the line
        line[0] = toupper(line[0]);
    	for (int i=0;i<strlen(line);i++){
            if(line[i]==' '){
                line[i+1] = toupper(line[i+1]);
            }
        }
        printf("%s", line);
    }
    return 0;
}
