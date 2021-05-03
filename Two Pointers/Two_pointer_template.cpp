/*
 * Two pointers template:
 * Background: Find all the combinations of 2 numbers in an array such their sum is equal to a given target;
 * We can use one number for only one time, but there is possibility that repeated numbers occur.
 * Step 1: sort the array
 * Step 2: find the answer
 * Reminder:
 * 1. Pruning: cut off the condition that is impossible as early as possible to improve time performance
 * 2. Skip the repeated terms to improve time performance.
 * 3. Check the real cases in this category for more inspiration and understanding.
 * Recommendation:
 * Check "3Sum" and "Container with most water" first. These two are the most fundamental cases.
 */


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> answer_book;
        if(size < 2) return answer_book;
        sort(nums.begin(),nums.end());
        if(nums[0] + nums[1] > target) return answer_book;
        int left = 0;
        int right = size-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                answer_book.push_back({nums[left],nums[right]});
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            };
            if(sum > target) right--;
            if(sum < target) left++;
        }
        return answer_book;
    }
};


int main(){
    // Enter your test data input
    vector<int> question = {};
    int target = 0;

    vector<vector<int>> answer_book;
    Solution handle = Solution();
    answer_book = handle.twoSum(question,target);
    for(int i = 0; i < answer_book.size(); i++){
        cout << "[" << answer_book[i][0] << "," << answer_book[i][1] << "]" << endl;
    }
    return 0;
}
