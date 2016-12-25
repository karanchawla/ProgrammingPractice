// Sample code to read in test cases:
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    char line[1024];
    fseek(file, 0, SEEK_END);
    unsigned long int len = (unsigned long)ftell(file);
    printf("%ld\n", len);
    
    return 0;
    }
