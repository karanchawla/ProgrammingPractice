#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateAbsoluteDiff(int n, vector<vector<int> > a)
{
    int primary_diag = 0;
    int secondary_diag = 0;
    for (int i = 0; i < n; ++i)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(i==j)
            {
                primary_diag += a[i][j];
            }
                
            if(i==n-j-1)
            {
                secondary_diag += a[i][j];
            }
                
        }
    }
    
    return abs(primary_diag - secondary_diag);
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    cout << calculateAbsoluteDiff(n,a);
    return 0;
}
