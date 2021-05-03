/*
 * Use two pointers to point at the current position of the "cursor" (fast pointer) and the last element
 * that is newly updated which is different from all the elements before it (slow pointer) respectively.
 * Fast pointer will go through all the elements from index 1 to n-1.
 * When ever nums[fast] == nums[fast-1], which means a repetition occurs, we increment fast by 1 but leave slow the same.
 * When ever nums[fast] != nums[fast-1], which means a different element is discovered, we copy the new value to nums[slow]
 * and increment both fast and slow by 1.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int fast, slow;
        fast = slow = 1;
        while (fast < nums.size()){
            if(nums[fast] == nums[fast-1]){
                fast++;
            } else{
                if(fast-slow > 0) nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};

int main() {
    // Input test data
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    // Test bench
    Solution handle = Solution();
    int len = handle.removeDuplicates(nums);
    cout << len << endl;
    cout << "[";
    for(int i = 0; i < nums.size()-1; i++){
        cout << nums[i] << ",";
    }
    cout << nums[nums.size()-1] << "]";
    return 0;
}
