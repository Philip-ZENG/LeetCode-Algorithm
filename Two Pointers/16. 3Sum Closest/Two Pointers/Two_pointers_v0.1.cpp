/* 
 * Mild changes are made based on "Two_pointers_v0.cpp"
 * Skip the repeated elements during each execution, which is the same as "15. 3Sum" question
*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long sum;
        long closest = INT_MAX;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int left = i+1;
                int right = n-1;
                while(left < right){
                    sum = nums[i] + nums[left] + nums[right];
                    if(abs(sum-target) < abs(closest-target)) closest = sum;
                    if(sum == target) return closest;
                    if(sum > target){
                        while(left < right && nums[right] == nums[right-1]) right--;
                        right--;
                    }else{
                        while(left < right && nums[left] == nums[left+1]) left++;
                        left++;
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
