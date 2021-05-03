/*
 * Use fast and slow two pointers to traverse through the array.
 * When the fast pointer meets the target value to remove, increment fast pointer by one but keep the slow pointer in original place
 * When the fast pointer dose not meet the target value to remove, increment both the fast and slow pointer by one.
 * copy the value from fast pointer to slow pointer.
 * Remark: Only copy values when fast pointers and slow pointers are not pointing at the same element.
 * Time complexity: O(n)
 * Space complexity: O(1)
 * The idea in this question is very similar to that in the question "Remove Duplicates from Sorted Array", you may check for reference
 */


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int fast, slow;
       fast = slow = 0;
        while (fast < nums.size()){
            if(nums[fast] != val){
                if(fast - slow > 0) nums[slow] = nums[fast];
                fast++;
                slow++;
            } else{
                fast++;
            }
        }
        return slow;
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
