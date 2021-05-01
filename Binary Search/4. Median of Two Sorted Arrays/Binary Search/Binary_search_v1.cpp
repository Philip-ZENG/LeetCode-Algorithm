
// Improve the kth smallest number algorithm with binary search 
// Reach a time complexity of O(min(m,n))


// Central idea:
// We can partition array1 and array2 at position i , j respectively, such that
// max(nums1[i-1], nums2[j-1) <= min(nums1[i], nums2[j])
// Then, the median number would be 
// Total length is even number: (max(nums1[i-1], nums2[j-1) + min(nums1[i], nums2[j])) / 2
// Total length is odd number: (max(nums1[i-1], nums2[j-1)
//
// Also observe the equation:
// Total length is even number: i + j = (n + m) / 2
// Total length is odd number: i + j = (n + m + 1) / 2
// Since "/" in c++ is automatically floor division, so the equation:
// i + j = (n + m + 1) / 2
// holds for both the even length or odd length as floor(1/2) = 0


// Comments: This approach is too much "mathematics", probably not very useful for general applications.
// Don't waste your time in this approach when you revisit this question.
// Too much boundary conditions.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = (n + 1) / 2; // Divider of array1
        int j = (n + m + 1) / 2 - i; // Divider of array2

        return solve(nums1,nums2,i,j);
    }

    double solve(vector<int> &nums1, vector<int> &nums2, int& i, int& j){
        int n = nums1.size();
        int m = nums2.size();
        int length = n + m;

        if(n == 0 || m == 0){ // Special conditions when one array is empty
            if(n == 0 && m == 0){
                throw exception();
            }
            else{
                double answer;
                if(n == 0){
                    answer = (m%2 != 0) ? nums2[m/2] : (nums2[m/2] + nums2[m/2-1])/2.0 ;
                }
                else{
                    answer = (n%2 != 0) ? nums1[n/2] : (nums1[n/2] + nums1[n/2-1])/2.0 ;
                }
                return answer;
            }
        }

        if (i == n || j == m){ // Boundary condition when one partitioner reaches right most position
            if(i == n && j == 0){
                if(length%2 == 0){
                    return (nums1[n-1] + nums2[0])/2.0;
                }
                else{
                    return nums1[n-1];
                }
            }
            if(i == 0 && j == m){
                if(length%2 == 0){
                    return (nums1[0] + nums2[m-1])/2.0;
                }
                else{
                    return nums2[m-1];
                }
            }

            if (i == n && max(nums1[i - 1], nums2[j - 1]) > nums2[j]) {
                j = j + 1;
                i = (n + m + 1) / 2 - j;
                return solve(nums1,nums2,i,j);
            }
            else if (j == m && max(nums1[i - 1], nums2[j - 1]) > nums1[i]) {
                i = i + 1;
                j = (n + m + 1) / 2 - i;
                return solve(nums1,nums2,i,j);
            }
            else{ // Ready for outputting answers
                if (length % 2 == 0) {
                    if (i == n) {
                        return (max(nums1[i - 1], nums2[j - 1]) + nums2[j]) / 2.0;
                    }
                    if (j == m) {
                        return (max(nums1[i - 1], nums2[j - 1]) + nums1[i]) / 2.0;
                    }
                }
                else {
                    return max(nums1[i - 1], nums2[j - 1]);
                }
            }
        }
        else if(i == 0 || j == 0){ // Boundary condition when one partitioner reaches left most position
            if (i == 0 && nums2[j-1] > min(nums2[j], nums1[i])) {
                i = i + 1;
                j = (n + m + 1) / 2 - i;
                return solve(nums1,nums2,i,j);
            }
            else if (j == 0 && nums1[i-1] > min(nums1[i], nums2[j])) {
                j = j + 1;
                i = (n + m + 1) / 2 - j;
                return solve(nums1,nums2,i,j);
            }
            else{ // Ready for outputting answers
                if (length % 2 == 0) {
                    if (i == 0) {
                        return (nums2[j - 1] + min(nums1[i],nums2[j]))/ 2.0;
                    }
                    if (j == 0) {
                        return (nums1[i - 1] + min(nums1[i],nums2[j]))/ 2.0;
                    }
                }
                else {
                    if(i == 0){
                        return nums2[j-1];
                    }
                    else{
                        return nums1[i-1];
                    }
                }
            }
        }
        else { // Most of the "normal cases"
            if (max(nums1[i - 1], nums2[j - 1]) > min(nums1[i], nums2[j])) {
                if (nums1[i] < nums2[j - 1]) {
                    i = i + 1;
                    j = (n + m + 1) / 2 - i;
                    return solve(nums1,nums2,i,j);
                }
                else{ // nums2[j] < nums2[i - 1]
                    j = j + 1;
                    i = (n + m + 1) / 2 - j;
                    return solve(nums1,nums2,i,j);
                }
            }
            else{ // Ready for outputting answers
                if (length % 2 == 0) {
                    return (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) / 2.0;
                }
                else{
                    return max(nums1[i - 1], nums2[j - 1]);
                }
            }
        }
        return 0;
    }
};

int main(){
    vector<int> nums1 = {4};
    vector<int> nums2 = {1,2,3,5};
    Solution handle = Solution();
    cout << handle.findMedianSortedArrays(nums1,nums2);
}
