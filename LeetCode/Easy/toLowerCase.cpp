#include <iostream>
#include <string>

using namespace std; 

string toLowerCase(string input)
{
	for(char &c: input)
	{
		if(c >= 'A' && c <= 'Z') 
			c += 32;
	}

	return input;
}