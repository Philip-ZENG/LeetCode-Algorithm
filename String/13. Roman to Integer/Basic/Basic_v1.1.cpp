/*
 * This version sacrifies certain code performance for a clearer logical understanding
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {

    unordered_map<char, int> oneCharRomanValues{
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
    };

public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size()-1 && oneCharRomanValues[s[i]] < oneCharRomanValues[s[i+1]]){
                result -= oneCharRomanValues[s[i]];
            } else{
                result += oneCharRomanValues[s[i]];
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
