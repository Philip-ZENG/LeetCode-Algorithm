// Merging the two sorted array

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_array;
        int i, j;
        i = j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                merged_array.push_back(nums1[i]);
                i++;
            }else{
                merged_array.push_back(nums2[j]);
                j++;
            }
        }
        while(j < nums2.size()){
            merged_array.push_back((nums2[j]));
            j++;
        }
        while(i < nums1.size()){
            merged_array.push_back((nums1[i]));
            i++;
        }
        int left = floor((merged_array.size()-1)/2.0);
        int right = ceil((merged_array.size()-1)/2.0);
        float mean = (merged_array[left] + merged_array[right])/2.0;
        return mean;
    }
};



int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    Solution handle = Solution();
    cout << handle.findMedianSortedArrays(nums1,nums2);
}
