#include <iostream>

using namespace std;

bool judgeCircle(string moves) 
{
    int v = 0;
    int h = 0;
    for (char ch : moves) {
        switch (ch) {
            case 'U' : v++; break;
            case 'D' : v--; break;
            case 'R' : h++; break;
            case 'L' : h--; break;
        }
    }
    return v == 0 && h == 0;
}

int main()
{
	string input = "UD";
	std::cout << judgeCircle(input);

	return 0;
}