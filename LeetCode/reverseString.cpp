#include <iostream> 
#include <string> 
#include <stack>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        stack<char> reversedString;
        string newString;
        for(string::iterator it = s.begin(); it!= s.end(); ++it)
        {
            reversedString.push(*it);
        }
        for(string::iterator it = s.begin(); it!= s.end(); ++it )
        {
            newString.push_back(reversedString.top());
            reversedString.pop();
        }
        return newString;
    }
};


int main(void)
{
    Solution sol;
    string s = "Fear is the mind killer.";
    string t;
    t = sol.reverseString(s);
    cout << t << endl;
    return 0; 
}