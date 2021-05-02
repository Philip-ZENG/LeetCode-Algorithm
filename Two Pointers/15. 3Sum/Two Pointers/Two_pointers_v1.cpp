// Use two pointers to solve the problem
// Step 1. sort() function in c++:
// Time complexity = O(nlogn) in average (presumably quick sort)
// Step 2. Find answers:
// Use two pointers to combine the 2nd and 3rd nested for-loop into 1 for-loop.
// We know that for a + b + c = 0, when a and b are fixed, there would be only one c that satisfy the condition
// The next b take would be b'
// If a + b' + c' = 0
// Then c' < c since b' > b
// So as b is increasing, we can search for c from the right end of the array.
// Time complexity = O(n^2)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer_book;
        int n = nums.size();
        sort(nums.begin(),nums.end()); // Use c++ embedded sort() function (quick sort) instead of the user implemented merge sort
        if(n < 3 || nums[0] > 0){ // When the number of elements in the array is less than 3, no answers are possible.
            return answer_book;
        }
        if(n == 3){
            if(nums[0]+nums[1]+nums[2] == 0){
                answer_book.push_back({nums[0],nums[1],nums[2]});
            }
            return answer_book;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return answer_book; // Since the array is already sorted, so when the first element if larger than 0 , no answers are possible
            }
            if(i == 0 || nums[i] != nums[i-1]){
                int L = i+1;
                int R = n-1;
                while(L<R) {
                    long sum = nums[i] + nums[L] + nums[R];
                    if (sum == 0) {
                        answer_book.push_back({nums[i], nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L + 1]) L++; // Get over the repeated terms
                        while (L < R && nums[R] == nums[R - 1]) R--; // Get over the repeated terms
                        L++;
                        R--;
                    }
                    // Make both pointer move in a more flexible manner.
                    if (sum > 0) R--;
                    if (sum < 0) L++;
                }
            }
        }
        return answer_book;
    }
};


int main() {
    Solution handle = Solution();
    vector<int> question = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = handle.threeSum(question);
    for(int i =0; i < answer.size(); i++){
        for(int j=0; j < answer[i].size(); j++){
            cout << answer[i][j] << endl;
        }
    }
    return 0;
}
