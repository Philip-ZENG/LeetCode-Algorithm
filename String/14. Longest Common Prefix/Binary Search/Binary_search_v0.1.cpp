/**
 * This version use the idea of "binary search"
 * The longest common prefix must be a substring of the shortest string, which means the index of the longest common prefix must lie between
 * [0,minLength].
 * We use binary search idea to find the index for the longest common prefix substring:
 *
 * Initially we define the left and right pointer as 1 and minLength
 * Each time we take the middle point and check whether it is the common prefix :
 * # If [0,mid] is the common prefix, then the longest common prefix must be equal or longer than this instance.
 *   We will move the left pointer to the middle point.
 * # If [0,mid] is not the common prefix, then the longest common prefix must be shorter than this instance.
 *   We will move the right pointer to the middle point.
 *
 * With clarification about the loop exit condition, we can find the longest common prefix.
 *
 *
 * Time complexity = O(mnlogm).
 * m is the length of the shortest string, n is the size of the vector
 * We will do binary search repetition for logm times, each iteration we will test for at most mn chars
 *
 * Space complexity = O(1)
 * 
 * Note: Code length is improved
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // find the minimum length of the string elements
        int minLength = 200;
        for(int i = 0; i < strs.size(); i++){
            minLength = min(int(strs[i].size()), minLength);
        }
        // if "" is one of the elements in the vector, we return ""
        if(minLength == 0){
            return "";
        }
        // for most of the general cases, when each string has length >= 1
        int right = minLength;
        int left = 0;
        int mid;
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            if (commonPrefix(strs, mid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return strs[0].substr(0, left);
    }

    // check whether the substring sliced from [0,len] is the common prefix of all the strings
    bool commonPrefix(vector<string> & strs, int len){
        string str0 = strs[0].substr(0, len);
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            string str = strs[i];
            for (int j = 0; j < len; ++j) {
                if (str0[j] != str[j]) {
                    return false;
                }
            }
        }
        return true;
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

    strs = {"cir","car"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {"",""};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {"ab", "a"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;
    return 0;
}
