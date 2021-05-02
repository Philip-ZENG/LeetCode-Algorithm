// Use two pointers to solve the problem
// Step 1. Merge sort:
// Time complexity = O(nlogn)
// Step 2. Find answers:
// Use two pointers to combine the 2nd and 3rd nested for-loop into 1 for-loop.
// We know that for a + b + c = 0, when a and b are fixed, there would be only one c that satisfy the condition
// The next b take would be b'
// If a + b' + c' = 0
// Then c' < c since b' > b
// So as b is increasing, we can search for c from the right end of the array.
// Time complexity = O(n^2)
// This version merely pass the test


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        merge_sort(nums,0,nums.size()-1);
        vector<vector<int>> answer_book;
        for(int i = 0; i < nums.size(); i++){
            int k = nums.size()-1;
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < nums.size(); j++){
                    if((j == i+1 || nums[j] != nums[j-1]) && j < k){
                        while(nums[i] + nums[j] + nums[k] > 0 && j+1 < k){ // Check nums[k] from the left end of the array
                            k--;
                        }
                        if(nums[i] + nums[j] + nums[k] == 0){
                            answer_book.push_back({nums[i],nums[j],nums[k]});
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
