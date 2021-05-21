/***
 * Simply iterate through all the string characters.
 * When illegal situation occurs, returns zero;
 * When overflow or underflow occurs, returns the MAX or MIN of integer type;
 * When everyting is ok, simply add up each digits
 *
 * Notice: The key here is to keep track of all the exception cases
 */



#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool sign_flag = true; // Indicate whether the number is a positive or negative one
        bool sign_occur = false; // Check whether the sign has occurred or not
        bool digit_occur = false; // Check whether a digit has occurred or not
        int length = s.length();
        // Map string to the corresponding digit in integer
        unordered_map<char,int> digits = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},\
                                            {'6',6},{'7',7},{'8',8},{'9',9}};

        // Find the first non zero number in the string format as the highest digit
        int i = 0;
        char cursor;
        while (i < length) {
            cursor = s[i];
            // If there are characters other than numbers and signs or empty space before the first non-zero digit, returns 0;
            if (digits.find(cursor) == digits.end() && cursor != '+' && cursor != '-' && cursor != ' ') {
                return 0;
            // Empty space after sign is illegal
            } else if( (sign_occur || digit_occur) && cursor == ' '){
                return 0;
            }
            // Check on the sign of the number
            else if(cursor == '+' or cursor == '-'){
                if(!sign_occur && !digit_occur){
                    if(cursor == '+'){
                        sign_flag = true;
                    } else{
                        sign_flag = false;
                    }
                    // If no sign occurs, it is by default a positive number
                    sign_occur = true;
                } else return 0; // When more than one sign occur at the same time, or a sign occurs after zero, it would be an illegal input
            }
            // Check whether we the number starts: when the first non-zero digit occurs, the number starts
            else if(digits.find(cursor) != digits.end() && cursor != '0') {
                break;
            }
            // Mark the digit occur flag as ture when zero occurs, to help get rid of the "0 124" or "0+123" cases
            else if(cursor == '0'){
                digit_occur = true;
            }
            i++;
        }

        long long result = 0;
        bool highest_digit = true;
        // Add up each digit to generate the integer
        while(i < length && digits.find(s[i]) != digits.end()){
            // When processing the highest digit, we will add the sign to it
            if(highest_digit){
                if(sign_flag){
                    result = digits[s[i]];
                } else{
                    result = -1*digits[s[i]];
                }
                highest_digit = false;
            } else{
                // If it is a positive number
                if(sign_flag){
                    if(result > INT_MAX) return INT_MAX;  // If the result overflow, return the max integer type
                    else result =  result*10 + digits[s[i]];
                }
                // If it is a negative number
                else{
                    if(result < INT_MIN) return  INT_MIN;  // If the result underflow, return the min integer type
                    else result = result*10 - digits[s[i]];
                }
            }
            i++;
        }
        // Check overflow and underflow cases again
        if(result > INT_MAX) return INT_MAX;
        else if (result < INT_MIN) return  INT_MIN;
        else return result;
    }
};

int main() {
    string s = "0 123";
    Solution handle = Solution();
    std::cout << handle.myAtoi(s) << std::endl;
    return 0;
}
