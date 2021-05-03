/*
 * Use the two pointer idea to solve the problem
 * Set two pointers at the left and right end of the array respectively
 * Calculate the area and move the pointer with smaller height
 * Loop until two pointers meet each other
 * Proof of the two pointers idea:
 * Assume the left and right pointer is pointing at number x and y respectively, the distance between two pointer is t
 * Assume x <= y, and now we fix the left pointer and move the right pointer leftward
 * We now have left->x and right-> y', distance between two pinter is t'
 * So the old area = min(x,y)*t
 * New area = min(x,y')*t'
 * When y' > y: min(x,y') = x = min(x,y)
 * When y' <= y: min(x,y') <= min(x,y)
 * Also t' < t since right pointer moves leftward
 * So, new area <= old area, no matter how we move the right pointer with left pointer fixed
 * The left pointer cannot be the boundary of any answers with larger area than the (x,y) one
 * So we would abandon the left pointer and move it rightward to search for other possibilities
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while(left < right){
            int area = (right - left) * min(height[left],height[right]);
            if(area > max_area) max_area = area;
            if(left < right && height[right] <= height[left]) right--;
            else left++;
        }
        return max_area;
    }
};



int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7,4,5,6,7,7};
    Solution handle = Solution();
    cout << handle.maxArea(height) << endl;
    return 0;
}
