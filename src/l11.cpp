#include <algorithm>
#include <vector>
#include <cmath>


class Solution {
public:
    // left index, right index
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        while (right - left != 0) {
            //
            max = std::max(max, (right - left) * std::min(height[right], height[left]));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};