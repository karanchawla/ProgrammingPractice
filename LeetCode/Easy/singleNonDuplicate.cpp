#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         for (int i = 0; i < nums.size(); i+= 2) {
        if (nums[i] != nums[i+1]) {
            return nums[i];
            break;
            }
        }
    }
};

int main(void)
{
	int arr[] = {1,1,2,3,3,4,4,8,8};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;

	cout << sol.singleNonDuplicate(nums);

	return 0;
}