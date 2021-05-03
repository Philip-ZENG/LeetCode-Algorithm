/*
 * Use two pointer idea to solve the problem
 * Absolutely the same idea as "3 Sum" with only one more layer of for-loop
 * Step 1: Sort the array
 * Step 2: Find the answer
 * Time complexity: O(n^3)
 * * Step 1: O(nlogn)
 * * Step 2: O(n^3)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer_book;
        if(n < 4) return answer_book;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0 && nums[i] > target) return answer_book;
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < n; j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
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
            }
        }
        return answer_book;
    }
};


int main() {
    // Test data input
    vector<int> question = {1,0,-1,0,-2,2};
    int target = 0;

    // Test bench
    vector<vector<int>> answer_book;
    Solution handle = Solution();
    answer_book = handle.fourSum(question,target);
    if(answer_book.size() == 0){
        cout << "[]" << endl;
    }
    for(int i = 0; i < answer_book.size(); i++){
        cout << "[" << answer_book[i][0] << "," << answer_book[i][1] << "," << answer_book[i][2] << "," << answer_book[i][3] << "]" << endl;
    }
    return 0;
}
