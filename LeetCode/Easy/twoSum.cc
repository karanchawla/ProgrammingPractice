#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/two-sum/description/
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> result;
    for(int i = 0; i<nums.size(); i++)
    {
        if(map.find(target - nums[i])!=map.end())
        {
            result.push_back(i);
            result.push_back(map[target - nums[i]]);
            return result;
        }

        map[nums[i]] = i;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4, -1, 0, 11};
    int target = 14;
    vector<int> result = twoSum(nums, target);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;

}
