/*
 * Standard traversal:
 * Traverse through out the whole array, and find the target value, then erase it.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        while(it != nums.end()){
            if(*it == val){
                nums.erase(it);
            } else{
                it = it + 1;
            }
        }
        return nums.size();
    }
};


int main() {
    // Input test data
    vector<int> nums = {3,2,2,3};

    // Test bench
    Solution handle = Solution();
    int len = handle.removeElement(nums,3);
    cout << len << endl;
    cout << "[";
    for(int i = 0; i < nums.size()-1; i++){
        cout << nums[i] << ",";
    }
    cout << nums[nums.size()-1] << "]";
    return 0;
}
