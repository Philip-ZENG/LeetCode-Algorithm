/*
 * This version use Deterministic Finite Automaton to solve the problem
 * About Automaton:
 * At each moment, we have a state S and we have an input C, according to C we change to the next state S'.
 * So we need to build up a table to illustrate the state transformation relationships
 *
 * The state transformation table is shown below:
 * --------------------------------------------------------------
 * |            | ' '       | +/-       | number    | other     |
 * | start      | start     | signed    | in_number | end       |
 * | signed     | end       | end       | in_number | end       |
 * | in_number  | end       | end       | in_number | end       |
 * | end        | end       | end       | end       | end       |
 * --------------------------------------------------------------
 *
 * Explanation on each state:
 * start: state before any sign or number has occurred
 * signed: sign detected
 * in_number: number digit has been inputted
 * end: number transformation terminates
 *
 * Explanation on char to int typecast used in this file:
 * char a = '4';
 * int ia = a - '0';
 * Explanation:
 * a - '0' is equivalent to ((int)a) - ((int)'0'), which means the ascii values of the characters are subtracted from each other.
 * Since 0 comes directly before 1 in the ascii table (and so on until 9),
 * the difference between the two gives the number that the character a represents.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Automaton {
    // Class argument definition
    string state = "start"; // state indicator
    unordered_map<string, vector<string>> table = { // implement the state transformation table
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    // Recognize the corresponding input for a given character to the index in the state transition table
    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

public:
    int sign = 1; // indicate the sign of the number
    long long ans = 0;

    bool get(char c) {
        state = table[state][get_col(c)]; // read in a character and recognize the next state based on the current state and input
        // When enter number input states
        if (state == "in_number") {
            // c - '0' = ((int)c) - ((int)'0'); Further explanation please refer to the note at the beginning of this file
            ans = ans * 10 + c - '0';
            // Notes: we may use max(), min(), ? statement to replace the handwritten conditional judgement and simplify the code
            // Tackle with overflow and underflow situation
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        // When enter sign judgement state
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
        else if (state == "end")
            return false;
        return true;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str) // iterate through string, iterator format
            // for each character, we make judge the next state and do corresponding operations;
            // if an end state is raised, we terminate the loop
            if(!automaton.get(c)) break;
        return automaton.sign * automaton.ans; // add the sign for answer
    }
};

 int main() {
    string s = "0 123";

    Solution handle = Solution();
    std::cout << handle.myAtoi(s) << std::endl;
    return 0;
}
