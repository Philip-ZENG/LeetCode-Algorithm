/*
 * This version uses two pointers, but the essence is indeed a brute force approach
 * We iterate through the whole string and check whether each substring is a palindrome.
 * Several improvements are made such that its performance is better than that of a two nested for-loop version brute force approach.
 * Use two pointers to slice substrings and check whether it is the longest palindrome
 * Left pointer starts at index 0 and goes all the way to index n-1; (left pointer is fixed for each iteration)
 * Right pointer starts at index n-1 and goes leftward: each time s[left] != s[right] decrease right by 1;
 * Time complexity:O(n^2)
 */


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int left, right;;
        int n = s.length();
        string longest = "";
        for(left = 0; left < n; left++){
            right = n-1;
            if(right-left+1 <= longest.length()) break;
            while(left <= right){
                if(s[left] == s[right]){
                    string substring;
                    if(left == right){
                        substring = s[left];
                    } else{
                        substring = s.substr(left,right-left+1);
                    }
                    if(substring.length() > longest.length() && palindrome(substring)){
                        longest = substring;
                        break;
                    }
                }
                right--;
            }
        }
        return longest;
    }

    bool palindrome(string s){
        if(s.length() == 1){
            return true;
        } else{
            int left = 0;
            int right = s.length()-1;
            while(left <= right){
                if(s[right] != s[left]) return false;
                left++;
                right--;
            }
            return true;
        }
    }
};


int main() {
    // Input test data
    string s = "babad";

    // Test bench
    Solution handle = Solution();
    std::cout << handle.longestPalindrome(s) << std::endl;
    return 0;
}
