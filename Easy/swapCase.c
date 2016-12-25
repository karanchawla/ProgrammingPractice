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
    	for (int i=0;i<strlen(line);i++){
            if(line[i]>='A' && line[i]<='Z'){
                line[i] = tolower(line[i]);
            }else if(line[i]>='a' && line[i]<='z'){
                line[i] = toupper(line[i]);
            }
        }
        printf("%s", line);
    }
    return 0;
}
