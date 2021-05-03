/* 
 * Underlying idea is the same as "Two_pointers_v0" 
 * More judegement condition is added to help pruning (“剪枝”)
 * This can increase the actual time performance of our program to a great extent, though the time complexity is not improved.
 * Time complexity: O(n^3)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer_book;
        if(n < 4) return answer_book;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n-3; i++){
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break; // Cut when the sum of the smallest numbers already exceeds the target.
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue; // Cut when the first number adds with the three largest number is still smaller than target.
            if(i > 0 && nums[i] == nums[i-1]) continue; // Cut when repeated value occurs.
            for(int j = i+1; j < n-2; j++){
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[j] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1;
                int right = n-1;
                long sum;
                while(left < right){
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        answer_book.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    if(sum > target) right--;
                    if(sum < target) left++;
                }
            }
        }
        return answer_book;
    }
};
