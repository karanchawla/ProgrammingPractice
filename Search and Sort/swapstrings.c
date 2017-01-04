#include <stdio.h>
#include <string.h>

void swap(char const **, char const **);

void swap(char const ** p1, char const **p2){
	char const *temp = *p1;
	*p1 = *p2;
	*p2 = temp; 
}

int main(void){
	char const *str1 = "Fear is a mind killer.";
	char const *str2 = "I must not Fear.";
	swap(&str1, &str2);
	printf("%s %s", str1, str2);
 	getchar();
}