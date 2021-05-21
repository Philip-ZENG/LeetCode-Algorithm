/*
 * This directly checking all the conditions is a kind of not practical in implementing this task
 * We should try to use back tracking or other techniques to handle it.
 * 
 * This version can solve some basic questions, but can not efficiently handle the one with "char*" and ".*"
 */


#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int s_ptr = 0;
    int p_ptr = 0;
    char pre_char;
    bool isMatch(string s, string p){
        while(p_ptr < p.length() && s_ptr < s.length()){ //&& s_ptr < s.length() is erased
            // When there is a character followed by '*'
            if((p_ptr+1) < p.length() && p[p_ptr] != '.' && p[p_ptr+1] == '*'){
                pre_char = p[p_ptr];
                while (s_ptr < s.length() && s[s_ptr] == pre_char){
                    s_ptr++;
                }
                if(s_ptr > s.length()-1){
                    if(p.find(p[p_ptr],p_ptr+1) != string::npos) s_ptr--;
                }
                else{
                    // Handle special case like s="aaa", p="a*a"
                    if(p[p_ptr] == p[p_ptr+2]) s_ptr--;
                }
                p_ptr = p_ptr+2;
            }
            // When a '.' is encountered
            else if(p[p_ptr] == '.'){
                // When there is a '.' followed by '*'
                if((p_ptr+1) < p.length() && p[p_ptr+1] == '*'){
                    // if ".*" is the last two character in p string
                    if(p_ptr+1 == p.length()-1) {
                        return true;
                    }
                    // if there are other characters after ".*" in p string, check on the char just after '*'
                    else{
                        char next_match = p[p_ptr+2];
                        bool match = false;
                        // deal with condition like s="aaa", p=".*a"; s = "aaba", p=".*a"
                        if(s[s_ptr] == next_match){
                            while (s_ptr < s.length() && s[s_ptr] == next_match){
                                s_ptr++;
                            }
                            // deal with condition like s="aaa", p=".*a";
                            if(s_ptr == s.length()){
                                s_ptr--;
                            }
                        }

                        // When facing general cases like s = "aabc", p = ".*c"
                        while (s_ptr < s.length() && !match){
                            if(s[s_ptr] == next_match){
                                match = true;
                                break;
                            }
                            s_ptr++;
                        }

                        if(s_ptr > s.length()-1) {
                            if (next_match == '.') {
                                s_ptr--;
                                match = true;
                            }
                        }

                        // if there is a match for the next character after '*', we would forward the p_ptr by 2
                        if(match) {
                            p_ptr = p_ptr + 2;
                        } else{
                            return false;
                        }
                    }
                }
                else{
                    s_ptr++;
                    p_ptr++;
                }
            }
            // if there is match between the two position pointed by both pointers
            else if(s[s_ptr] == p[p_ptr]){
                s_ptr++;
                p_ptr++;
            }
            // id none of the matching position is satisfied, it would indicate a match failure
            else{
                return false;
            }
        }

        while (p_ptr < p.length() && s_ptr > s.length() - 1){
            // When there is a character followed by '*'
            if((p_ptr+1) < p.length() && p[p_ptr] != '.' && p[p_ptr+1] == '*'){
                p_ptr = p_ptr+2;
            }
            // When there is a '*' following "."
            else if(p[p_ptr] == '.' && (p_ptr+1) < p.length() && p[p_ptr+1] == '*'){
                p_ptr = p_ptr+2;
            }
            else{
                break;
            }
        }

        // To exit the while loop, there could be situations like s = "aa", p = "a", we need a further test
        if(p_ptr > p.length()-1 && s_ptr > s.length()-1){
            return true;
        } else{
            return false;
        }
    }
};

// Testing module
int main() {
    string s = "ab";
    string p = ".*..";
    Solution handle = Solution();

    std::cout << handle.isMatch(s,p);
    return 0;
}
