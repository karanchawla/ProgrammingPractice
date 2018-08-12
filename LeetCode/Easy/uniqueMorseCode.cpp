#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std; 

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse_code ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> gen_codes;
    
    for(auto word : words) {
        string code = "";
        for(auto ch : word)
            code += morse_code[ch - 'a'];
        gen_codes.insert(code);
    }
    
    return gen_codes.size();
}

int main()
{
	vector<string> words = {"gin", "zen", "gig", "msg"};
	cout << uniqueMorseRepresentations(words);

	return 0;
}