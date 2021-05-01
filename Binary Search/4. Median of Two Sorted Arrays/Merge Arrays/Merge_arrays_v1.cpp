// The approach is the same as merging two arrays, but we don't actually merge
// the two arrays "physically", but instead use variables, "pointers" instead to represent the idea.
// Time complexity is still O(m+n) since we need to go through all the elements one by one in the two array
// Space complexity is improved to O(1) comparing to "Merge_arrays_v0.cpp", since only a constant number of variables are needed for each execution

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size = m+n;
        int ptr1, ptr2;
        ptr1 = ptr2 = 0;
        int small, large;
        small = large = 0;
        int count = 0;
        // if size is an odd number, find the number at index floor(size/2)
        // if size is an even number, find the number at index size/2 - 1 & floor(size/2)
        while(count <= floor(size/2) && ptr1 < n && ptr2 < m){
            if(nums1[ptr1] <= nums2[ptr2]){
                small = large;
                large = nums1[ptr1];
                ptr1++;
            }else{
                small = large;
                large = nums2[ptr2];
                ptr2++;
            }
            count ++;
        }
        while(count <= floor(size/2) && ptr1 < n){
            small = large;
            large = nums1[ptr1];
            ptr1++;
            count ++;
        }
        while(count <= floor(size/2) && ptr2 < m){
            small = large;
            large = nums2[ptr2];
            ptr2++;
            count ++;
        }
        if(size%2 == 0){
            return (small + large)/2.0 ;
        }else{
            return large;
        }
    }
};

int main() {
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    Solution handle = Solution();
    cout << handle.findMedianSortedArrays(nums1,nums2);
}
