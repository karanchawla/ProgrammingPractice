//Karan Chawla
//Reverse sentence without reversing each word

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//utility function to swap chars
void swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

//utility function to reverse each substring
void reverse(char *str, int begin, int end)
{
	while(begin < end)
	{
		swap(&str[begin++],&str[end--]);
	}

}

//function to reverse a sentence without reversing the individual words
void reverseSentence(char *str, size_t size)
{
	size_t n = size;

	int low = 0;
	int high = 0;

	for(int i=0; i<size; i++)
	{
		if(str[i]==' ')
		{
			reverse(str,low,high);
			low = high = i + 1;
		}
		else 
			high = i;
	}

	//reverse last word
	reverse(str, low, high);

	reverse(str, 0, size);
}

//utility function to print array
void printArray(char *str, size_t size)
{
	for (int i = 0; i <= size; ++i)
	{	
		printf("%c", str[i]);
		/* code */
	}
}


//Driver program
int main(void)
{
	//Please tell me you get the reference?
	char str[] = "I shall not fear. Fear is the mind killer. Fear is the little death that brings total obliteration.";

	size_t size = (sizeof(str)/sizeof(*str)) - 2;
	
	reverseSentence(str, size);
	
	printArray(str,size);

	return 0;
}