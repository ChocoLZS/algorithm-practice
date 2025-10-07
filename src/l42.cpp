#include "leetcode.hpp"
#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
public:
    // 真正的双指针
    // 每列遍历所有元素，寻找左侧、右侧最高的柱子，然后填雨水
    static int trap1(std::vector<int>& height) {
        if (height.size() <= 2) return 0;
        int result = 0;
        int i = 1;
        for(; i < height.size() - 1; i++) {
            int lheight = 0;
            int rheight = 0;
            for (int l = i - 1; l >= 0; l--) {
                lheight = std::max(height[l], lheight);
            }
            for (int r = i + 1; r <= height.size() - 1; r++) {
                rheight = std::max(height[r], rheight);
            }
            int min_height = std::min(lheight, rheight);
            result += min_height > height[i] ? min_height - height[i] : 0;
        }
        return result;
    }

    // dp
    // 左右遍历时记录最高度
    // 两个dp数组，用于存放 lheight, rheight
    // lheight[i] 是i坐标对应的最大左高度
    // rheight[i] 是i坐标对应的最大右高度
    // lheight[i] = max(height[i-1], lheight[i-1])
    // rheight[i] = max(height[i+1], rheight[i+1])
    static int trap2(std::vector<int>& height) {
        if (height.size() <= 2) return 0;
        int result = 0;
        int i = 1;
        std::vector<int> lheights(height.size(), 0);
        lheights[0] = height[0];
        std::vector<int> rheights(height.size(), 0);
        rheights[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++) {
            lheights[i] = std::max(lheights[i-1], height[i-1]);
        }
        for(int i = height.size() - 2; i >= 0; i--) {
            rheights[i] = std::max(rheights[i+1], height[i+1]);
        }
        for(int i = 1; i < height.size()-1;i ++) {
            int min_height = std::min(lheights[i], rheights[i]);
            result += min_height > height[i] ? min_height - height[i] : 0;
        }
        return result;
    }
};

int main() {
    std::vector<int> raw_height = {0,1,0,2,1,0,1,3,3,3,3,2,1,2,1};
    std::vector<int>& height = raw_height;
    int result = Solution::trap2(height);
    std::printf("result is %d\n", result);
    return 0;
}