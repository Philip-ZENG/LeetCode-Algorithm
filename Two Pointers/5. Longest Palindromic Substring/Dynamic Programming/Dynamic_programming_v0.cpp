/*************************************************************************************************
 * Use dynamic programming idea
 * Use an n*n 2d vector (grid) to store the state of each substring
 * Mark the corresponding entry as true if the substring is palindrome and mark as false otherwise
 * Use dp[i][j] to represent the substring with index [i...j]
 * Several conditions are listed below in judging whether a substring is palindrome:
 * 1. When the substring has length 1 : must be palindrome
 * 2. When the substring has length 2: if substr[0] == substr[1], then is palindrome
 * 3. When the substring has length 3: if substr[0] == substr[2], then is palindrome
 * 4. When the substring has length larger than 3: the same as s[i-1...j-1] if s[i] == s[j]
 ***********************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int left, right, begin, max_length;
        begin = 0; // Record the begin index of the currently longest palindrome
        max_length = 1; // Record the length of the currently longest palindrome
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        /**
         * @param length : length of the substring we are looking at in this iteration
         */
        for(int length = 2; length <= n; length++){
            for(int j = 0; j < n; j++){
                left = j;
                right = length + left - 1;
                if(right > n-1) break;
                if(s[left] != s[right]){
                    dp[left][right] = false;
                } else{
                    if(length <= 3){
                        dp[left][right] = true;
                    } else{
                        dp[left][right] = dp[left+1][right-1];
                    }
                }
                if(dp[left][right] && length > max_length){
                    begin = left;
                    max_length = length;
                }
            }
        }
        return s.substr(begin,max_length);
    }
};


int main() {
    // Input test data
    string s = "ac";

    // Test bench
    Solution handle = Solution();
    std::cout << handle.longestPalindrome(s) << std::endl;
    return 0;
}
