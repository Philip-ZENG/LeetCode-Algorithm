/**
 * Principle:
 * Observe the index relationships and then use these equation to arrange each char into corresponding position
 * For a zigzag string sequence with number of rows given by n:
 * Each "cycle" has 2n-2 elements
 * When m = index%(2n-2) <= n-1, then the element should be placed at row m
 * When m = index%(2n-2) > n-1, then the element should be placed at row (2n-2-m)
 * Use these two equation, we can find out the position of each char in the zigzag placement pattern by iterating through all
 * the characters in the string
 *
 * Remark:
 * 1. This version use an vector of string to store char for each line instead of using a 2D integer vector to store the index of
 * each char at its corresponding position.
 * 2. This version use iterator in strings and vectors instead of using index to iterate through them. This may be a more efficient 
 * approach.
 * 
 *
 * Time complexity : O(n)
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * @para j : Which row the character should be at in a zigzag pattern placement
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> rows(min(numRows,int(s.length())));
        int j = 0;
        for(char c : s){
            if( j <= numRows-1){
                rows[j] += c;
            } else{
                rows[2*numRows-2-j] += c;
            }
            j = (j+1) % (2*numRows-2);
        }
        string answer;
        for(string row : rows){
            answer += row;
        }
        return answer;
    }
};


int main() {
    // Input test data
    Solution handle = Solution();
    string question = "PAYPALISHIRING";
    int numRows = 3;

    // Test bench
    std::cout << handle.convert(question,numRows) << std::endl;
    return 0;
}
