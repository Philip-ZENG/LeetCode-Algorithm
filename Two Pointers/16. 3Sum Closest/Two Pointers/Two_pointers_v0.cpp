/*
 * Classical two pointers question
 * Step 1: Sort the array
 * Step 2: Find the answer by shrinking both boundary of the array (moving left and right pointers)
 * Remark: Very similar to the question "3 Sum", so the basic idea is basically the same
 * Overall time complexity: O(n^2)
 * * Step 1 time complexity: O(nlogn)
 * * Step 2 time complexity: O(n^2)
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
            for(int j = i+1; j < n; j++){
                int left = j;
                int right = n-1;
                while(left < right){
                    sum = nums[i] + nums[left] + nums[right];
                    if(abs(sum-target) < abs(closest-target)){
                        closest = sum;
                    }
                    if(sum == target){
                        return closest;
                    }
                    else if(sum > target){
                        right--;
                    }else{
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
