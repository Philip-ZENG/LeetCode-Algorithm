/***
 * In this version, backtrack recursion will be used to handle the problem of
 * ".*" and "a*", the basic idea is that try out every possible skipping values when ever
 * any of these combination occurs.
 *
 * This version uses multiple recursion structure, we use two function to call each other recursively.
 * This helps us verify whether there is a match in the substrings recursively
 * Time Complexity: Exponential
 */


#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

    bool isMatch(string s, string p){
        // for special case when s == ""
        if(s.length() == 0){
            int p_ptr = 0;
            if(p.length()%2 != 0){
                return false;
            }
            else{
                while (p_ptr < p.length()){
                    if(p[p_ptr+1] == '*'){
                        p_ptr+=2;
                    } else{
                        return false;
                    }
                }
                return true;
            }
        }
        // for most of the cases when s != ""
        else{
            return verify(s,p,0,0);
        }
    }


    bool verify(string s, string p, int s_ptr, int p_ptr){
        while(p_ptr < p.length() && s_ptr < s.length()){
            // Deal with the case of ".*"
            if(p[p_ptr] == '.' && p[p_ptr+1] == '*'){
                // if ".*" is the last two character in p string
                if(p_ptr+1 == p.length()-1) {
                    return true;
                }
                // if there are other characters after ".*" in p string
                else {
                    s_ptr = s_ptr + backTrackDot(s.substr(s_ptr), p.substr(p_ptr), 0, 0);
                    p_ptr += 2;
                }
            }
            // Deal with the case of "*" following any char except "."
            else if((p_ptr+1) < p.length() && p[p_ptr] != '.' && p[p_ptr+1] == '*'){
                s_ptr = s_ptr + backTrackChar(s.substr(s_ptr), p.substr(p_ptr), 0, 0);
                p_ptr += 2;
            }
            // if there is match between the two position pointed by both pointers
            else if(s[s_ptr] == p[p_ptr]){
                s_ptr++;
                p_ptr++;
            }
            // deal with '.' without '*' case
            else if(p[p_ptr] == '.'){
                s_ptr++;
                p_ptr++;
            }
            // if none of the matching position is satisfied, it would indicate a match failure
            else{
                return false;
            }
        }

        // check out the conditions when s is already exhausted but p is not
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
        if(s.length() == 0 && p.length() == 0){
            return true;
        }
        else if(p_ptr > p.length()-1 && s_ptr > s.length()-1){
            return true;
        }
        else{
            return false;
        }

    }

    // back track function to deal with ".*" circumstances
    int backTrackDot(string s_, string p_, int s_ptr, int p_ptr){
        // Try each possible value of * repetition, when a '.*' combination occurs
        int possible_s_ptr;
        for(int i = 0; i < 20; i++){
            possible_s_ptr = s_ptr + i;
            if (possible_s_ptr > s_.length()-1){
                return possible_s_ptr;
            }
            else {
                // When the current attempt failed, we continue next attempt
                if (verify(s_.substr(possible_s_ptr), p_.substr(p_ptr+2), 0,0) == false) {
                    continue;
                }
                // When the current attempt is a matched condition
                else {
                    return possible_s_ptr;
                }
            }
        }
        return possible_s_ptr;
    }

    // back track function to deal with "a*" situations
    int backTrackChar(string s_, string p_, int s_ptr, int p_ptr){
        int possible_s_ptr;
        for(int i = 0; i < 20; i++){
            possible_s_ptr = s_ptr + i;
            // if the two letter does not match
            if (s_[possible_s_ptr] != p_[p_ptr]){
                return possible_s_ptr;
            }
            // if the two letter matches
            else {
                // When the current attempt failed, we continue next attempt
                if (verify(s_.substr(possible_s_ptr), p_.substr(p_ptr+2), 0,0) == false) {
                    continue;
                }
                // When the current attempt is a matched condition
                else {
                    return possible_s_ptr;
                }
            }
        }
        return true;
    }
};


// Testing module
int main() {
    Solution handle = Solution();
    string s;
    string p;

    s = "mississippi";
    p = "mis*is*p*.";
    if(handle.isMatch(s,p) == false){
        cout << "pass" << endl;
    } else{
        cout << "unpass" << endl;
    }

    s = "mississippi";
    p = "mis*is*p*.";
    if(handle.isMatch(s,p) == false){
        cout << "pass" << endl;
    } else{
        cout << "unpass" << endl;
    }
    
    return 0;
}
