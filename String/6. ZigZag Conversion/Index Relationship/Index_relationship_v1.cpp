/**
 * Principle:
 * Observe the index relationships and then use these equation to arrange each char into corresponding position
 * We will iterate through the elements at each row and generate the final return value after this iteration.
 * When we are iterating through the first or last row, we only need to consider the chars in the column of zigzag pattern,
 * which is the char has index%(numRows-1) == 1
 * When we are iterating through other rows, we need to consider elements in the bevel edge (斜边)
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @param i : Index of the row we are currently at in the zigzag pattern
 * @param j : Number of chars in the cycles we have gone through
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(min(numRows,int(s.length())));
        string answer;
        int cycleLength =  2*numRows-2;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j + i < s.length(); j += cycleLength){
                answer += s[j+i];
                if(i != 0 && i != numRows-1 && j + cycleLength - i < s.length()){
                    answer += s[j + cycleLength - i];
                }
            }
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
