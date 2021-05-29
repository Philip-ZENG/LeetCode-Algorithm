/*
 *
 * This version uses dynamic programming method
 * The key idea is also a kind of iteration but we use a 2d array to achieve the "iteration"
 * This approach increases time and space performances
 *
 * The following is an explanation of the idea:
 * If we use f[i][j] to denote a function that gives the result of whether the [0]...[i] elements in s
 * matches the [0]...[j] elements in p. Then we can have the following dynamic programming expression
 *
 *
 *                                | = f[i-1][j-1] , if matches(s[i],p[j])
 *           | if p[j] is not '*' |
 *           |                    | = false , if otherwise
 * f[i][j] = |
 *           |                | = f[i-1][j-2] or f[i][j-2], if matches(s[i],p[j])
 *           | if p[j] is '*' |
 *                            | = f[i][j-2], otherwise
 *
 *
 * matches(s[i],p[j]) is a function to judge whether s[i] and p[j] matches
 *
 *                      | true , if s[i] = p[j] or p[j] = '.'
 * matches(s[i],p[j]) = |
 *                      | false , otherwise
 *
 * Time complexity: Linear, O(mn), m,n is the length of the two string
 *
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:


    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        /*
         * Lambda Expression feature since c++11
         * A function defined inside a function:
         * an unnamed function object capable of capturing variables in scope.
         * [&] (implicitly capture the used automatic variables by reference)
         * auto type can accept different types of return values
         */

        auto matches = [&](int i, int j) {
            // i equals zero means when s is an empty string
            if (i == 0) {
                return false;
            }
            // since j starts from 1, so [j-1] is the jth elements' index in the string
            // so if p[j] is a ".", then there is a match for any s[i]
            if (p[j - 1] == '.') {
                return true;
            }
            // s[i-1] and p[j-1] indicates the first ith and jth elements in s and p respectively because the index starts from 0
            return s[i - 1] == p[j - 1];
        };


        /*
         * 2D array declaration (grid) with size (m+1) * (n+1) (because the index starts from 0, we need the n+1 row to indicate the first nth element)
         * vector constructor with parameter (n,value)
         * n: Initial container size (i.e., the number of elements in the container at construction).
         * value: Value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
         * without value given, the default value for an integer vector would be zero
        */

        // notice the index of vector elements also starts form 0
        vector<vector<int>> f(m + 1, vector<int>(n + 1,0));
        // initial condition, f[0][0] means two empty string, this would be a match for this case
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            // for each fixed i we iterate through all the j values
            for (int j = 1; j <= n; ++j) {
                // check for conditions when ".*" or "char*" occurs
                if (p[j - 1] == '*') {
                    // "|=" bitwise inclusive OR and assignment operator;  C |= 2 is same as C = C | 2
                    // f[i][j] = f[i][j-2] will always holds because in this case ".*" or "a*" indicates "zero repetition", it represents nothing
                    f[i][j] |= f[i][j - 2];
                    // if s[i] equals p[j-1], then we will have f[i][j] = f[i][j-1] because the ".*" or "a*" will represents multiple repetition of some char
                    // an overwritten on [i][j] will happen if it is a match condition
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                // cases without "*", then the f[i][j] = f[i-1][j-1] if s[i] equals p[j]
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        // after all these "induction" and iteration, we will return the result whether the first m elements in s matches the
        // the first n elements in p
        return f[m][n];
    }
};


// Testing module
int main() {
    Solution handle = Solution();
    string s;
    string p;

    s = "abcc";
    p = "ab.*";
    if(handle.isMatch(s,p) == true){
        cout << "pass" << endl;
    } else{
        cout << "unpass" << endl;
    }

    s = "mississippi";
    p = "mis*is*p*.";
    if(handle.isMatch(s,p) == false){
        cout << "pass" << endl;
    } else{
        cout << "unpass" << endl;
    }

    return 0;
}

