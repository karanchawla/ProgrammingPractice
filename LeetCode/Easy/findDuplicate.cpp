#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans;
        for(std::vector<int>::iterator i=nums.begin(); i!=nums.end()-1;++i)
        {          
            if(*i==*(i+1))
            {
                ans = *i;
                break;
            }
            
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    cout << *(v.end()-1);

    return 0;
}