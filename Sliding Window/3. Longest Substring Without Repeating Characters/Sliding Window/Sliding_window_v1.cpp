// Using the sliding window strategy
// Get rid of the containner unordered set and use "pointers" directly to mark the position of char
// Improve time and space complexity

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,k,max;
        i = j = k = max = 0;
        for(i = 0; i < s.length(); i++){ // check all the char on the left of index i
            for(j = k; j < i; j++){ // k is to mark the position where a repeated char is detected
                if(s[j] == s[i]){
                    max = max < i-k ? i-k : max;
                    k = j+1;
                    break;
                }
            }
        }
        return max < i-k ? i-k : max;
    }
};

int main(){
    Solution node = Solution();
    cout << node.lengthOfLongestSubstring("abcabcbb");
}
