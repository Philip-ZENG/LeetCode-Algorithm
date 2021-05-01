// Brute force search

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(nums[j] + nums[i] == target){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        return {};
    }
};
