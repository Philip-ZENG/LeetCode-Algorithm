/*
 * Standard traversal
 * Traverse the whole array, delete any element that is the same as the one before it.
 * This version directly modified on the original array and erase the repeated elements.
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
        vector<int>::iterator it = nums.begin()+1; // Starts from the second element
        int ptr = nums[0];
        while (it != nums.end()){
            if(*it == ptr){
                nums.erase(it); // iterator will point to the next element after erase operation
            } else{
                ptr = *it;
                it++;
            }
        }
        return nums.size();
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
