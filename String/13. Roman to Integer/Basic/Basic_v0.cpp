/**
 * This version checks for the "two letters roman number characters" first and then check the
 * "single letter roman number characters".
 *
 * Time complexity  = O(1)
 * # since the length of each string is at most 15, so we can give an output within 15 loops
 * Space complexity = O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
    const pair<char,int> oneCharRomanValues[7]{
        {'M',1000},
        {'D',500},
        {'C',100},
        {'L',50},
        {'X',10},
        {'V',5},
        {'I',1}
    };

    const pair<string,int> twoCharRomanValues[6]{
        {"CM",900},
        {"CD",400},
        {"XC",90},
        {"XL",40},
        {"IX",9},
        {"IV",4}
    };

public:
    int romanToInt(string s) {
        int size = s.size();
        int ptr = 0;
        int result = 0;
        bool flag;
        while(ptr < size){
            flag = false;
            // test for the two letters "roman number characters"
            for(int i = 0; i < 6; i++){
                if(s.substr(ptr,2) == twoCharRomanValues[i].first){
                    result += twoCharRomanValues[i].second;
                    ptr += 2;
                    flag = true;
                    break;
                }
            }
            // test for the single letter "roman number character"
            if(!flag){
                for(int j = 0; j < 7; j++){
                    if(s[ptr] == oneCharRomanValues[j].first){
                        result += oneCharRomanValues[j].second;
                        ptr ++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};


int main() {
    Solution handle = Solution();
    string s = "LVIII";
    std::cout << handle.romanToInt(s) << std::endl;
    s = "IX";
    std::cout << handle.romanToInt(s) << std::endl;
    s = "MCMXCIV";
    std::cout << handle.romanToInt(s) << std::endl;
    return 0;
}
