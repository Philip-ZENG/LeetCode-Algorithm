/**
 * This version uses backtrack to iterate through all the possible combinations.
 * We can view each combination as a branch of a tree:
 * "23" would can be shown as the following tree
 *                  2
 *        a         b         c
 *        3         3         3
 *     e  f  g   e  f  g  e  f  g
 * We use back track to traverse through each branch in Depth First Search Manner
 *
 * Time complexity = O(3^m*4^n)
 * m is the number of digit which has 4 corresponding letters, n is the number of digit which has 3 corresponding letters in the given input string,
 * 3^m*4^n is the number of rounds we need to do backtrack calling (iterate through all the possible conditions)
 * Space complexity = O(m+n)
 * Space usage is mainly related to how many layers of recursion calls, m+n is the maximum value of recursion layers
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

public:
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        // if no elements are in the vector
        if(digits.empty()){
            return combinations;
        }
        string combination;
        // start backtracking to simulate the "nested" for loop idea
        backtrack(combinations,digits,0,combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations,const string& digits, int index, string& combination){
        // backtrack ending condition : when the result string length equals to the digits.size()
        if(index == digits.size()){
            combinations.push_back(combination);
        }
        else{
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter); // add one letter to the end of string
                backtrack(combinations, digits, index + 1, combination); // check for the next layer of the "combination tree"
                combination.pop_back(); // erase the last letter from the end of string
            }
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
