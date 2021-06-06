/**
 * This version is based on a further understanding of the rules in interpretation of roman numbers :
 * # When a smaller number is on the left of a larger number, we will subtract that smaller number
 * # When a larger number is on the left of a smaller number, we add the larger number to the result
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

public:
    int romanToInt(string s) {
        int size = s.size();
        int ptr = 0;
        int curr = 0;
        int next = 0;
        int result = 0;
        while(ptr <= size){
            if(ptr == size){
                result += next;
                break;
            }
            for(int i = 0; i < 7; i++){
                if(s[ptr] == oneCharRomanValues[i].first){
                    curr = next;
                    next = oneCharRomanValues[i].second;
                    break;
                }
            }
            if(curr < next) result -= curr;
            else result += curr;
            ptr++;
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
