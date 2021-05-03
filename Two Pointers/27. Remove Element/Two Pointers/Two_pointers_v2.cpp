/*
 * Since the order of elements in the array is not restricted, we may swap any of the target value
 * with an value at the end of the array and decrement the array length by 1. 
 * (That is simply copy the element at the end of the array to the position where a target value is found,
 * since we will decrement the array length by 1, we don't actually need to swap)
 * We use two pointers starting at the begin (left pointer) and end (right pointer) of the array respectively.
 * When the left pointer points to the target, we copy the number at right pointer's position to left pointer's position
 * and move right pointer leftward by 1.
 * When the left pointer is not pointing to the target, simply increment left pointer by 1, keep the right pointer.
 * Improvement:
 * This avoid repeated replacement which may happen in "Two_pointers_v0.cpp"
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right){
            if(nums[left] == val){
                nums[left] = nums[right];
                right--;
            } else{
                left++;
            }
        }
        return left;
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
