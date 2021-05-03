/*
 * Standard brute force approach using four nested for-loop
 * Step 1: Sort the array to avoid problems raised by repeated elements
 * Step 2: Find the answer
 * Skip the repeated elements to increase time performance
 * Time complexity: O(n^4)
 * Time out error
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
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < n; j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        for(int k = j+1; k < n; k++){
                            if(k == j+1 || nums[k] != nums[k-1]){
                                for(int p = k+1; p < n; p++){
                                    if(p == k+1 || nums[p] != nums[p-1]){
                                        if(nums[i] + nums[j] + nums[k] + nums[p] == target){
                                            answer_book.push_back({nums[i],nums[j],nums[k],nums[p]});
                                        }
                                    }
                                }
                            }
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
    vector<int> question = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;

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
