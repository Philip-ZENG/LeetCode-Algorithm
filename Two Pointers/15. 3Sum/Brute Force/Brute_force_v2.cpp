// Basic idea is changed: We don't try to list all the possible answers and remove the repeated ones afterwards
// Instead we sort the array first and only use unrepeated numbers to construct our answers.
// We will list all the possible answers with the restriction that a <= b <= c;
// This version will has two major steps:
// 1. Sorting the array:
// Use merge sort with time complexity O(nlogn)
// 2. List all the possible answers satisfying a <= b <= c and a+b+c=0:
// Use triple for-loop, time complexity is O(n^3)
// In total:
// Time complexity = O(n^3)
// This works but still exceeds the time limits, an over_time error is thrown out.


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        merge_sort(nums,0,nums.size()-1);
        vector<vector<int>> answer_book;
        for(int i=0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){ // These conditions are used to avoid repeated terms to increase the time performance
                for(int j=i+1; j < nums.size(); j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        for(int k=j+1; k < nums.size(); k++){
                            if( k == j+1 || (nums[k] != nums[k-1])){
                                if(nums[i] + nums[j] + nums[k] == 0) {
                                    answer_book.push_back({nums[i], nums[j], nums[k]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return answer_book;
    }

    // left and right are the index of the elements in the array
    void merge_sort(vector<int> &array, int left, int right){
        if(left < right){
            int partition = (left + right)/2; // Divide
            merge_sort(array,left,partition); // Conquer
            merge_sort(array,partition+1,right); // Conquer
            merge(array,left,partition,right); // Combine
        }
    }
    
    // Standard implementation of merge sort according to the "Introduction to Algorithm"
    void merge(vector<int> &array,int left,int partition,int right){
        vector<int> left_half;
        vector<int> right_half;
        for(int i=left; i <= partition; i++){
            left_half.push_back(array[i]);
        }
        for(int j=partition+1; j <= right; j++){
            right_half.push_back(array[j]);
        }
        left_half.push_back(INT_MAX);
        right_half.push_back(INT_MAX);
        int ptr = left;
        int left_ptr = 0;
        int right_ptr = 0;
        while(ptr <= right){
            if(left_half[left_ptr] <= right_half[right_ptr]){
                array[ptr] = left_half[left_ptr];
                left_ptr++;
            }else{
                array[ptr] = right_half[right_ptr];
                right_ptr++;
            }
            ptr++;
        }
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
