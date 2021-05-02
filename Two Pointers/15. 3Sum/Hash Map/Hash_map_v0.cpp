// This problem is essentially a two sum problem, so we can preprocess the given array and make use of the code
// in the two sum questions.
// The idea of divide and conquer is used here.
// Time complexity needs further improvement
// Time complexity for this version is still O(n^3)
// Though with hashmap implemented two sums, the bottle neck is in the merge step, which costs O(n^3)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer_book;
        // Divide the three sum problem into n two sum problems, n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            // Initialize the problem set for a instant of two sum problem
            vector<int> local_nums = nums;
            int target = - nums[i];
            vector<int>::iterator it;
            it = local_nums.begin();
            it = it+i;
            local_nums.erase(it);

            // Solve the instance of two sum problem
            vector<vector<int>> partial_answer;
            partial_answer = twoSum(local_nums,target);
            for(int j = 0; j < partial_answer.size(); j++){
                partial_answer[j].push_back(-target);
                sort_number(partial_answer[j]); // Sort the each element in the partial answer in to required sequence
            }

            // Merge the partial answers into the answer_book
            // Time complexity is O(n^2)
            bool flag;
            for(int k = 0; k < partial_answer.size(); k++){
                flag = true;
                for(int l = 0; l < answer_book.size(); l++){
                    if(partial_answer[k] == answer_book[l]){
                        flag = false;
                    }
                }
                if(flag){
                    answer_book.push_back(partial_answer[k]);
                }
            }
        }

        // Sort the answer_book into required sequence
        sort_vector(answer_book);
        return answer_book;
    }

    // Time complexity with unordered_map, which is a hashmap, is O(nlogn)
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> hashtable;
        vector<vector<int>> answer;

        // Need to handle the repeated elements
        for(int i = 0; i < size; i++){
            int b = target - nums[i];
            if(hashtable.find(b) != hashtable.end()){
                answer.push_back({nums[hashtable.find(b)->second],nums[i]});
            }
            hashtable[nums[i]] = i;
        }
        return answer;
    }

    // Insertion sort with time complexity O(n^2)
    // This would probably be fine and will not affect the overall performance in large, since we are only sorting 3 numbers
    void sort_number(vector<int>& answer){
        for(int i = 1; i < answer.size(); i++ ){
            int key = answer[i];
            int j = i - 1;
            while(j >=0 && answer[j] > key){
                answer[j+1] = answer[j];
                j = j - 1;
            }
            answer[j+1] = key;
        }
    }

    // Insertion sort with time complexity O(n^2)
    // This could probably raise some problems, since when the answer book is large, this would be extremely time consuming
    void sort_vector(vector<vector<int>>& answer_book){
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
    }

};


int main() {
    Solution handle = Solution();
    vector<int> question = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    vector<vector<int>> answer = handle.threeSum(question);
    for(int i =0; i < answer.size(); i++){
        for(int j=0; j < answer[i].size(); j++){
            cout << answer[i][j] << endl;
        }
    }
    return 0;
}
