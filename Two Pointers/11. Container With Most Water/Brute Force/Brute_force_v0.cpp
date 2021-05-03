// List all the possible answers using double nested for-loop.
// Time complexity: O(n^2)
// Space complexity: O(1)
// Exceeds the time limit
// Time out error


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int width = min(height[i],height[j]);
                int length = j-i;
                int area = width * length;
                if(area > max) max = area;
            }
        }
        return max;
    }
};

int main() {
    vector<int> height = {1,2,1};
    Solution handle = Solution();
    cout << handle.maxArea(height) << endl;
    return 0;
}
