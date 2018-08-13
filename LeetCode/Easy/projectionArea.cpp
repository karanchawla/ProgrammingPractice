#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int projectionArea(vector<vector<int>> grid) 
{
    int res = 0, n = grid.size();
    for (int i = 0, v = 0; i < n; ++i, res += v, v = 0)
        for (int j = 0; j < n; ++j)
            v = max(v, grid[i][j]);
    
    for (int j = 0, v = 0; j < n; ++j, res += v, v = 0)
        for (int i = 0; i < n; ++i)
            v = max(v, grid[i][j]);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j]) res++;
    return res;
}