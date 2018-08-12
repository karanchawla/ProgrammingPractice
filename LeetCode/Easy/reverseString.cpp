#include <iostream>
#include <string>

using namespace std; 

string reverseString(string s)
{
	if(s.length() == 0 || s.length() == 1) return s; 
	int length = s.length();
	for(int i = 0; i < length/2; i++)
	{
		char temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	} 

	return s;
}

int main()
{
	string s("Chemo");
	std::cout << reverseString(s);

	return 0;
}