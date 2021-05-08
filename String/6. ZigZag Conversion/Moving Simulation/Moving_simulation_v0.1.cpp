/**
 * Use a direction judgement flag to indicate whether the cursor should go up or go down in our simulation
 * When the cursor touches the up upper limit or bottom of the zigzag pattern we should change the moving direction
 * That is when current_rows%(numRows-1) == 0
 *
 * Remark: 
 * 1. We use a vector of strings to store the char in each line directly rather than storing the index of each char
 * in "index_relationship_v0.cpp", this would save some spaces.
 * 2. We further use iterator in the string / vector to replace index iteration, this may further improve time performance
 * Time complexity: O(n)
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(min(numRows,int(s.length())));
        int current_row = 0;
        bool going_down = false;

        for(char c : s){ // Modifications are made here
            if(current_row%(numRows-1) == 0){
                going_down = not going_down;
            }
            rows[current_row] += c;
            if(going_down){
                current_row++;
            }else{
                current_row--;
            }
        }

        string answer;
        for(string row : rows){ // Modifications are made here
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
