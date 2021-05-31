// pay attention to the use of "|=" and several indexing details due to the transformation of 
// the nth element and the index in string and f function


#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
    public:

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        auto match = [&](int i, int j){
            if(i == 0){
                return false;
            }
            if(p[j-1] == '.'){
                return true;
            }
            // because the [i-1] and [j-1] is the ith and jth elements in the string
            return s[i-1] == p[j-1];
        };

        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        f[0][0] = true;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // if we meet the combination of ".*" or "char*"
                if(p[j-1] == '*'){
                    // this always holds if ".*" or "char*" represents "nothing"
                    f[i][j] |= f[i][j-2];
                    // if s[i-1] equals p[j-2], then we can mark it as the same value as the situation before ".*" or "char*" occurs
                    // which means, this "*" represents multiple char in p
                    if(match(i,j-1)){
                        f[i][j] |= f[i-1][j];
                    }
                }
                // if do not have '.*' or 'char*' combination
                else{
                    // if s[i-1] equals p[j-1], then f[i][j] = f[i-1][j-1]
                    if(match(i,j)){
                        f[i][j] |= f[i-1][j-1];
                    }
                    // if s[i-1] not equal to p[j-1], then f[i][j] = false
                    else{
                        f[i][j] = false;
                    }
                }
            }
        }
        return f[n][m];
    }
};


// Testing module
int main() {
    Solution handle = Solution();
    string s;
    string p;

    s = "abcc";
    p = "ab.*";
    if (handle.isMatch(s, p) == true) {
        cout << "pass" << endl;
    } else {
        cout << "unpass" << endl;
    }

    s = "mississippi";
    p = "mis*is*p*.";
    if (handle.isMatch(s, p) == false) {
        cout << "pass" << endl;
    } else {
        cout << "unpass" << endl;
    }

    return 0;
}
