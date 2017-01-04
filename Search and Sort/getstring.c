#include <stdio.h> 

void read(void);

void read(void){
	char str[20];
	fgets(str,20,stdin);
	printf("%s\n", str);
	return;
}

int main(void){
	char str[20];
	read();
}