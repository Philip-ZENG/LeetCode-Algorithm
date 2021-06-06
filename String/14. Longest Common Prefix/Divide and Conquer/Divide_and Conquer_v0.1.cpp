/**
 * This version use the idea of "divide and conquer". We split the problem into smaller parts and
 * solve each of these small questions and combine the their results to form the final results.
 *
 * Time complexity : O(mn) ; m is the average length of all the strings, n is the size of the vector
 * Space complexity : O(mlogn) ; m is the space need for each layer of recursion, log n is the number of layer we can get during "divide" procedure
 * n is the size of the vector
 *
 * Notes: Some redundant codes are optimized and removed comparing to v0.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        return longestCommonPrefix(strs,0,strs.size()-1);
    }

    string longestCommonPrefix(vector<string> & strs, int left, int right){
        if(left == right) {
            return strs[left];
        }
        else{
            int mid = (left+right)/2;
            string commonA = longestCommonPrefix(strs,left,mid);
            string commonB = longestCommonPrefix(strs,mid+1,right);
            return commonPrefix(commonA,commonB);
        }
    }

    // combine : combine the results of solved small sub-problems
    string commonPrefix(const string & a, const string & b){
        int len = min(a.size(),b.size());
        for(int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                return a.substr(0,i);
            }
        }
        return a.substr(0,len);
    }
};



int main() {
    Solution handle = Solution();

    vector<string> strs = {"flower","flow","flight"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {"dog","racecar","car"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {""};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;

    strs = {"cir","car"};
    std::cout << handle.longestCommonPrefix(strs) << std::endl;
    return 0;
}
