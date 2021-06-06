/**
 * Small improvements are made based on the Basic_v1, unordered_map (implemented with hash map)
 * is used to further improve the code efficiency and simplify the code.
 * To decrease the times we need to search for matched value in the map, we use the idea in Basic_v1.
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
        int curr;
        int next = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size()){
                result += next;
                break;
            }
            curr = next;
            next = oneCharRomanValues[s[i]];
            if(curr < next){
                result -= curr;
            } else{
                result += curr;
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
