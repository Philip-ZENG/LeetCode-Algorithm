/**
 * This version we would scan in the "horizontal" direction, which means we compare the
 * #1 and #2 string and find their common prefix, and use the common prefix to compare with the
 * rest of all the other strings. The result gives the longest common prefix.
 *
 * Time complexity = O(mn) ; m is the length of the longest string in the vector, n is the number of elements in the vector
 * Space complexity = O(1)
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 1){
            return strs[0];
        }
        result = longestCommonPrefix(strs[0],strs[1]);
        for(int i = 2; i < strs.size(); i++){
            result = longestCommonPrefix(strs[i],result);
        }
        return result;
    }

    string longestCommonPrefix(string a, string b){
        int len = min(a.length(),b.length());
        string commonPrefix = "";
        for(int j = 0; j < len; j++){
            if(a[j] == b[j]){
                commonPrefix += a[j];
            } else{
                break;
            }
        }
        return commonPrefix;
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
