// Performance is extremely undesireable

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for(int i = 0; i < s.length(); i++){
            int count = 0;
            unordered_map<char,int> map;
            for(int j = i; j < s.length(); j++){
                if(map.find(s[j]) != map.end()){
                    break;
                }else{
                    count ++;
                    map[s[j]] = 0;
                }
            }
            if(count > longest){
                longest = count;
            }
        }
        return longest;
    }
};

int main(){
    Solution node = Solution();
    cout << node.lengthOfLongestSubstring("abcabcbb");
}
