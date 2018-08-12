#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std; 

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
{
    for(auto & row: A) reverse(row.begin(), row.end());
    for (auto & row : A) for (int & i: row) i^=1;
    return A;
}

int main()
{
	vector<vector<int>> v = {{1,1,0},{1,0,1},{0,0,0}};
	vector<vector<int>> result = flipAndInvertImage(v);

	return 0;
}