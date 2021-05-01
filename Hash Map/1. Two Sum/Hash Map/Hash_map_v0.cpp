// Use hasp map instead of two for loop to improve seaching efficiency
// Searching by hashmap has a linear time complexity

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> hashtable;

        for(int i = 0; i < size; i++){
            int b = target - nums[i];
            if(hashtable.find(b) != hashtable.end()){
                return {hashtable.find(b)->second,i};
            }else{
                hashtable[nums[i]] = i;
            }
        }
        return {};
    }
};
