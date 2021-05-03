// Standard brute force approach
// Triple nested for-loop
// Time complexity: O(n^3)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long sum;
        long closest = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum-target) < abs(closest-target)){
                        closest = sum;
                    }
                }
            }
        }
        return closest;
    }
};

int main() {
    // Input argument
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    // Test bench
    Solution handle = Solution();
    cout << handle.threeSumClosest(nums,target) << endl;
    return 0;
}
