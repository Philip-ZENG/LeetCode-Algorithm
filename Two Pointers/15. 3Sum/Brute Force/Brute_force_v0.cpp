// Workable but time complexity is not acceptable, which is O(n^3) or even worse
// Cannot pass the test in LeetCode : Time_out Error;

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer_book;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if((nums[i] + nums[j] + nums[k]) == 0){
                        vector<int> new_answer = sort_number(nums[i],nums[j],nums[k]);
                        // Check whether the answer already exists or not
                        bool flag = true;
                        for(int l = 0; l < answer_book.size(); l++){
                            if(answer_book[l] == new_answer){
                                flag = false;
                            }
                        }
                        if(flag){
                            answer_book.push_back(new_answer);
                        }
                    }
                }
            }
        }
        answer_book = sort_vector(answer_book);
        return answer_book;
    }

    vector<int> sort_number(int a, int b, int c){ // Insertion sort
        vector<int> answer = {a,b,c};
        for(int i = 1; i < answer.size(); i++ ){
            int key = answer[i];
            int j = i - 1;
            while(j >=0 && answer[j] > key){
                answer[j+1] = answer[j];
                j = j - 1;
            }
            answer[j+1] = key;
        }
        return answer;
    }

    vector<vector<int>> sort_vector(vector<vector<int>> answer_book){
        for(int i = 1; i < answer_book.size(); i++ ){
            vector<int> key = answer_book[i];
            int j = i - 1;
            while(j >=0 && answer_book[j][0] > key[0] ){
                answer_book[j+1] = answer_book[j];
                j = j - 1;
            }
            answer_book[j+1] = key;
        }
        for(int i = 1; i < answer_book.size(); i++ ){
            vector<int> key = answer_book[i];
            int j = i - 1;
            while(j >=0 && answer_book[j][0] == key[0] && answer_book[j][1] > key[1] ){
                answer_book[j+1] = answer_book[j];
                j = j - 1;
            }
            answer_book[j+1] = key;
        }
        return answer_book;
    }
};

int main() {
    Solution handle = Solution();
    vector<int> question = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = handle.threeSum(question);
    for(int i =0; i < answer.size(); i++){
        for(int j=0; j < answer[i].size(); j++){
            cout << answer[i][j] << endl;
        }
    }
    return 0;
}
