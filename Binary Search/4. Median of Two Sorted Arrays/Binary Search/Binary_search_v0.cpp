// Filter out half of the elements each time, use binary search to help
// Time complexity is redueced to O(log(m+n))
// Space complexity is O(1) since only a constant number of variables will be used for each inputs

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int length = m + n;
        int ptr1, ptr2;
        ptr1 = ptr2 = 0;
        int k = length / 2 + 1; // If the set has an odd number of numbers, take kth and k-1th smallest and calculate average
        if (length % 2 == 0) {
            int left = findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            k = floor(length / 2);
            ptr1 = ptr2 = 0;
            int right = findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            return (left+right)/2.0;
        } else {
            return findKthSmallest(ptr1, ptr2, k, nums1, nums2);
        }
    }
  
    // General algorithm to find the kth largest elements in the merged array.
    // Recursion is used.
    int findKthSmallest(int &ptr1, int &ptr2, int &k, vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(ptr2 == m){// When one of the two array has already been traversed, check the other array
            return nums1[ptr1+k-1];
        }
        else if(ptr1 == n){// When one of the two array has already been traversed, check the other array
            return nums2[ptr2+k-1];
        }
        else if(k == 1) {// Select the 1st largest element in valid array scope
            if (nums1[ptr1] >= nums2[ptr2]) {
                return nums2[ptr2];
            }
            else {
                return nums1[ptr1];
            }
        }
        else {
            if((ptr1 + k / 2 - 1) > n-1){ // When the length of array 1 is shorter than k, view nums1[k] as positive infinity, so return nums2[k]
                ptr2 = ptr2 + k / 2;
                k = k - k / 2;
                return findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            }
            else if((ptr2 + k / 2 - 1 > m-1)){ // When the length of array 2 is shorter than k, view nums2[k] as positive infinity, so return nums1[k]
                ptr1 = ptr1 + k / 2;
                k = k - k / 2;
                return findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            }
            else if (nums1[ptr1 + k / 2 - 1] <= nums2[ptr2 + k / 2 - 1]) { // Filter out half of the elements each time
                ptr1 = ptr1 + k / 2;
                k = k - k / 2;
                return findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            }
            else {
                ptr2 = ptr2 + k / 2;
                k = k - k / 2;
                return findKthSmallest(ptr1, ptr2, k, nums1, nums2);
            }
        }
    }
};

// need to handle the situation when the length difference between two array is large: when one array has only one element problem solved
// need to handle the situation when there are repeated elements

int main() {
    vector<int> nums1 = {1,3,7,9,10,43,86};
    vector<int> nums2 = {2,3,4,5,6,7,190};
    Solution handle = Solution();
    cout << handle.findMedianSortedArrays(nums1,nums2);
}
