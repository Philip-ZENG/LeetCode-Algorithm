/**
 * We check the chars with the same index for each element in the vector.
 * Once a difference is found we would return the value of the longest common prefix.
 * 
 * Time complexity = O(n^2) in the worst case
 * Space complexity = O(1)
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string LCP = "";
        // special case with only one string element in the vecotr
        if(strs.size()==1){
            return strs[0];
        }
        // check each position in the stirng from left to right
        for(int i = 0; i <= 200; i++){
            // check each string
            for(int j = 0; j < strs.size()-1; j++) {
                if (strs[j] == "" || i > strs[j].size()-1 || strs[j][i] != strs[j + 1][i]) {
                    return LCP;
                }
            }
            LCP += strs[0][i];
        }
        return LCP;
    }
};



int main() {
    Solution handle = Solution();

    vector<string> strs = {"flower","flow","flight"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {"dog","racecar","car"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {""};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;
    return 0;
}
