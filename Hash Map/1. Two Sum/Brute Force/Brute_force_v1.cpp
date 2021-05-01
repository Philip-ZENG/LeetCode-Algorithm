// Search pattern is imporved a little bit
// Search for the corresponding answer for any given number

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
            int b = target - nums[i];
            for(int j = i+1; j < size; j++){
                if(nums[j] == b){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        return {};
    }
};
