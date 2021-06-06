/**
 * This version uses the idea of greedy algorithm, which means we try to subtract the given num with the largest
 * possible number that can be expressed in Roman Number in current situation.
 * We subtract the given num with the largest "Roman Number Character" and continue the loop until the num is 0.
 * We connect each of these "Roman Number Character" together to form out results.
 *
 * The key concept of greedy algorithm is that we "take the largest possible value at the current moment".
 * Time complexity: O(1), for the largest number in this question, the number of loops would not exceed 15.
 * Space complexity: O(1)
 */


#include <iostream>
#include <string>

using namespace std;

class Solution {

    const pair<int,string> valueSymbles[13]{
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"}
    };

public:

    string intToRoman(int num) {
        string roman = "";
        while(num!=0){
            for(int i = 0; i < 13; i++){
                // for the current num, once there is a suitable "roman number character", we would exit the for loop and restart
                // the match again if num is still larger than 0.
                if(num >= valueSymbles[i].first){
                    roman += valueSymbles[i].second;
                    num -= valueSymbles[i].first;
                    break;
                }
            }
        }
        return roman;
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
