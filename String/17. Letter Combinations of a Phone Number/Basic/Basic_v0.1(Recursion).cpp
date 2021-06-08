/**
 * This version holds the essentially same core idea as version Basic_v0, however, we use self-calling functions instead of nested for loops
 * to reduce code repetition and increase code reuse rate.
 * 
 * Since the fundamental idea is the same, time and space performance has not been improved comparing to Basic_v0 version.
 * # This version makes use of the math relationship between the indexes and the times of repetition for each char 
 * # The "form" is "recursion" but the central idea is not strictly speaking strongly connected to the "recursion method"
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
        vector<string> answer = {};
        if(digits.empty()){
            return answer;
        }
        // calculate how many times each possible first char needs to repeat
        int permutationCount = 1;
        for(int a = 0; a < digits.size(); a++){
            permutationCount *= reference.at(digits[a]).size();
        }
        // push the correct times of repetitions of the possible first char into the vector
        for(int i = 0; i < reference.at(digits[0]).size(); i++){
            for(int j = 0; j < permutationCount/reference.at(digits[0]).size(); j++){
                answer.push_back(reference.at(digits[0])[i]);
            }
        }
        // use a self calling function to reduce code repetition
        permutation(digits.size()-1,digits,answer);
        return answer;
    }

    void permutation(int round,const string & digits,vector<string> & answer){
        if(round > 0){
            // calculate how many times each possible char with corresponding number needs to repeat
            int period = 1;
            for(int a = digits.size()-round+1; a < digits.size(); a++){
                period *= reference.at(digits[a]).size();
            }
            // control the repetition of each different possible char with corresponding number
            int index = 0;
            int end = reference.at(digits[digits.size()-round]).size();
            for(int k = 0; k < answer.size(); k++){
                answer[k] = answer[k]+reference.at(digits[digits.size()-round])[index];
                if((k+1)%period == 0){
                    index = (index+1)%end;
                }
            }
            // call itself to achieve the same function as nested for loop
            permutation(round-1,digits,answer);
        }
    }
};

int main() {
    Solution handle = Solution();

    string digits;
    vector<string> answer;

    digits = "39";
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

    digits = "999";
    answer = handle.letterCombinations(digits);
    for(auto & i : answer){
        std::cout << i << std::endl;
    }

    return 0;
}
