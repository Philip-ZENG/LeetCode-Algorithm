// Use the sliding window to check whether there is a repetition or not
// a b c d d
// [ ] a b c d d
// [ a ] b c d d
// [ a b ] c d d
// [ a b c d ] d
// a [ b c d ] d
// a b [ c d ] d
// a b c [ d ] d
// a b c d [ ] d
// a b c d [ d ]
// a b c d d [ ]


#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }

        int longest = 0;
        int right_ptr = 0;
        unordered_set<char> look_up;
        for(int left_ptr = 0; left_ptr < s.length(); left_ptr++){
            while(look_up.find(s[right_ptr]) == look_up.end() && right_ptr < s.length()){ // right_ptr < s.length() is used to get rid of the ending /0 of a string
                look_up.insert(s[right_ptr]);
                right_ptr++;
            }
            longest = max(longest, (right_ptr-1) - left_ptr + 1);
            look_up.erase(s[left_ptr]);
        }
        return longest;
    }
};

int main(){
    Solution node = Solution();
    cout << node.lengthOfLongestSubstring("asbc kdd");
}
