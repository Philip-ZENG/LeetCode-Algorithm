/**
 * This basic version solve the problem by writing the corresponding solution for each input string length.
 * The result is given by permutation using nested for loops.
 * However, the code is not concise and code efficiency needs further improvement.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

public:
    const unordered_map<char,vector<string>> reference = {
        {'2',{"a","b","c"}},
        {'3',{"d","e","f"}},
        {'4',{"g","h","i"}},
        {'5',{"j","k","l"}},
        {'6',{"m","n","o"}},
        {'7',{"p","q","r","s"}},
        {'8',{"t","u","v"}},
        {'9',{"w","x","y","z"}}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.empty()){
            return {};
        }
        if(digits.size() == 1){
            for(const auto & i : reference.at(digits[0])){
                answer.push_back(i);
            }
        }
        if(digits.size() == 2){
            for(int i = 0; i < reference.at(digits[0]).size(); i++){
                for(int j = 0; j < reference.at(digits[1]).size(); j++){
                    answer.push_back(reference.at(digits[0])[i]+reference.at(digits[1])[j]);
                }
            }
        }
        if(digits.size() == 3){
            for(int i = 0; i < reference.at(digits[0]).size(); i++){
                for(int j = 0; j < reference.at(digits[1]).size(); j++){
                    for(int k = 0; k < reference.at(digits[2]).size(); k++){
                        answer.push_back(reference.at(digits[0])[i]+reference.at(digits[1])[j]+reference.at(digits[2])[k]);
                    }
                }
            }
        }
        if(digits.size() == 4){
            for(int i = 0; i < reference.at(digits[0]).size(); i++){
                for(int j = 0; j < reference.at(digits[1]).size(); j++){
                    for(int k = 0; k < reference.at(digits[2]).size(); k++){
                        for(int l = 0; l < reference.at(digits[3]).size(); l++){
                            answer.push_back(reference.at(digits[0])[i]+reference.at(digits[1])[j]+reference.at(digits[2])[k]+reference.at(digits[3])[l]);
                        }
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution handle = Solution();

    string digits;
    vector<string> answer;

    digits = "23";
    answer = handle.letterCombinations(digits);
    for(auto & i : answer){
        std::cout << i << std::endl;
    }

    digits = "";
    answer = handle.letterCombinations(digits);
    for(auto & i : answer){
        std::cout << i << std::endl;
    }

    digits = "2";
    answer = handle.letterCombinations(digits);
    for(auto & i : answer){
        std::cout << i << std::endl;
    }

    return 0;
}
