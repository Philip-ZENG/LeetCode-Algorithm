/**
 * Observe the index relationships and then use these equation to arrange each char into corresponding position
 * For a zigzag string sequence with number of rows given by n:
 * Each "cycle" has 2n-2 elements
 * When m = index%(2n-2) <= n-1, then the element should be placed at row m
 * When m = index%(2n-2) > n-1, then the element should be placed at row (2n-2-m)
 * Use these two equation, we can find out the position of each char in the zigzag placement pattern by iterating through all
 * the characters in the string
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
        int length = s.length();
        if(numRows == 1){
            return s;
        }
        vector<vector<int>> order(numRows);
        int j = 0;
        for(int i = 0; i < length; i++){
            if( j <= numRows-1){
                order[j].push_back(i);
            } else{
                order[2*numRows-2-j].push_back(i);
            }
            j = (j+1) % (2*numRows-2);
        }
        string answer;
        for(int j = 0; j < numRows; j++){
            for(int k = 0; k < order[j].size(); k ++){
                answer = answer + s[order[j][k]];
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
