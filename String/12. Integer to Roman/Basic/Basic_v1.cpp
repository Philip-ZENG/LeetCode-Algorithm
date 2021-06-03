// A more concise coding implementation of direct mapping idea
// Use a string array to map each number at each digit to a specific string, this would gives the final result
// by combining each of the strings

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ones[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[4] = {"","M","MM","MMM"};
        return thousands[num/1000] + hundreds[num/100 - (num/1000)*10] + tens[(num%100-num%10)/10] + ones[num%10];
    }
};


int main() {
    Solution handle = Solution();

    std::cout << handle.intToRoman(3) << std::endl;
    std::cout << handle.intToRoman(9) << std::endl;
    std::cout << handle.intToRoman(58) << std::endl;
    std::cout << handle.intToRoman(20) << std::endl;
    return 0;
}
