#include <iostream>
#include <string>
#include <unordered_set>

using namespace std; 

// O(m+n)

int numJewelsInStones(string J, string S)
{
	int res = 0;
	unordered_set<char> setJ(J.begin(), J.end());
	for(char s: S) if(setJ.count(s)) res++; 

	return res;
}

int main()
{
	string J("aA");
	string S("a,jdaasdAA");
	std::cout << numJewelsInStones(J, S);

	return 0;
}