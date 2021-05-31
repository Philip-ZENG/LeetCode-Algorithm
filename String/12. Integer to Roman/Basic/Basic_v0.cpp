// 1 <= num <= 3999
// Direct interpretation with conditional expression can solve the problem

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int thousand_digit = num/1000;
        int hundred_digit = num/100 - thousand_digit*10;
        int tens_digit = num/10 - thousand_digit*100 - hundred_digit*10;
        int ones_digit = num - thousand_digit*1000 - hundred_digit*100 - tens_digit*10;

        string Roman = "";
        if(thousand_digit >=1){
            Roman += string(thousand_digit,'M');
        }

        if(hundred_digit >= 1 && hundred_digit <= 3){
            Roman += string(hundred_digit,'C');
        } else if(hundred_digit == 4){
            Roman += "CD";
        } else if(hundred_digit >= 5 && hundred_digit <= 8){
            Roman += "D";
            Roman += string(hundred_digit-5,'C');
        } else if(hundred_digit == 9){
            Roman += "CM";
        }

        if(tens_digit >= 1 && tens_digit <= 3){
            Roman += string(tens_digit,'X');
        } else if(tens_digit == 4){
            Roman += "XL";
        } else if(tens_digit >= 5 && tens_digit <= 8){
            Roman += "L";
            Roman += string(tens_digit-5,'X');
        } else if(tens_digit == 9){
            Roman += "XC";
        }

        if(ones_digit >= 1 && ones_digit <= 3){
            Roman += string(ones_digit,'I');
        } else if(ones_digit == 4){
            Roman += "IV";
        } else if(ones_digit >= 5 && ones_digit <= 8){
            Roman += "V";
            Roman += string(ones_digit-5,'I');
        } else if(ones_digit == 9){
            Roman += "IX";
        }

        return Roman;
    }
};

int main() {
    Solution handle = Solution();

    std::cout << handle.intToRoman(20) << std::endl;
    return 0;
}
