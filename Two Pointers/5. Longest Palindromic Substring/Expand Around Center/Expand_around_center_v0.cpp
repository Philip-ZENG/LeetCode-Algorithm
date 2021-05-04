/**
 * Use the idea that we will take each char in the string as a center and try to expand to each side
 * and see whether we can find the palindromes we are seeking for.
 * We use two pointers to help indicate the two boundary of out substring to be tested.
 *
 * Two cases are involved:
 * 1. The palindrome's length is an odd number => the center has one char
 * 2. The palindrome's length is an even number => the center has two chars
 *
 * Time complexity: O(n^2)
 */


#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        int left, right, begin, length, max_length;
        max_length = 1;
        length = 1;
        begin = 0;
        for(int i = 0; i < n; i++){
            int j = i; // i would be index of the last consecutive repeated char if any
            while (j < n && s[j] == s[j+1]){
                j++;
            }
            if(j != i){ // When there are repeated char occur in consecutive order. e.g. "aa","aaa","aaaa",...
                if((j-i+1) % 2 == 0){ // Even number of repetitions. e.g. "aa","aaaa"
                    i = i + (j-i)/2;
                    left = i-1;
                    right = i+2;

                } else { // Odd number of repetitions. e.g. "aaa", "aaaaa"
                    i = i + (j-i)/2;
                    left = i-1;
                    right = i+1;
                }
            } else{ // No repetitions
                left = i - 1;
                right = i + 1;
            }
            while (true){
                if(left < 0 || right >= n || s[right] != s[left]){
                    length = right - left - 1;
                    break;
                }
                right++;
                left--;
            }
            if(length > max_length){
                begin = i - (length-1)/2;
                max_length = length;
            }
        }
        return s.substr(begin,max_length);
    }
};


int main() {
    // Input test data
    string s = "bbbb";

    // Test bench
    Solution handle = Solution();
    std::cout << handle.longestPalindrome(s) << std::endl;
    return 0;
}
