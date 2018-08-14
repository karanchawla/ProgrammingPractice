#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result; 
    if (nums.size()==0 || nums.size()==1 || nums.size()==2) return result; 

    for(int i = 0 ; i < nums.size()-2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int a = nums[i];
        int low = i + 1;
        int high = nums.size() - 1;

        while(low < high)
        {
            int b = nums[low];
            int c = nums[high];
            if(a+b+c == 0)
            {
                vector<int> triplet;
                triplet.push_back(a);
                triplet.push_back(b);
                triplet.push_back(c);

                result.push_back(triplet);
                while(low < high && nums[low] == nums[low+1]) low++;
                while(low < high && nums[high] == nums[high - 1]) high--;
                low++;
                high--; 
            }
            else if(a+b+c > 0)
            {
                while(low < high && nums[high] == nums[high - 1]) high--;
                high--;
            }
            else
            {
                while(low < high && nums[low] == nums[low+1]) low++;
                low++;
            }

        }
    }

    return result; 
}