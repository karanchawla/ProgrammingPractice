#include <iostream> 
#include <string> 
#include <stack>


class Solution
{
public:
	std::string reverseVowels(std::string s);
};

//Returns a string with the vowels reversed
std::string Solution::reverseVowels(std::string s)
{
	std::stack<char> vowels;
	for (std::string::iterator it = s.begin(); it < s.end(); ++it)
	{
		if(*it=='a' || *it=='e' || *it=='i' || *it=='o' || *it=='u' || *it=='A' || *it=='E' || *it=='I' || *it=='O' || *it=='U')
			vowels.push(*it);
	}

	std::string newString;
	for (std::string::iterator it = s.begin(); it < s.end(); ++it)
	{
		if(*it=='a' || *it=='e' || *it=='i' || *it=='o' || *it=='u' || *it=='A' || *it=='E' || *it=='I' || *it=='O' || *it=='U')
		{			
			newString.push_back(vowels.top());
			vowels.pop();
		}
		else 
		{
			newString.push_back(*it);
		}
	}

	return newString;
}

int main(void)
{
	Solution sol;
	std::string s = "aA";
	std::string t;
	t = sol.reverseVowels(s);
	std::cout << t << std::endl;
	return 0; 
}