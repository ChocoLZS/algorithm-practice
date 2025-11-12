#include <cstdio>
#include <type_traits>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // 使用map来存储最后出现的index
    // 这个方法是，将相同的num分类并排
    // 虽然不是题解，但是很有意思
    void sortColors_not_answer(std::vector<int>& nums) {
        std::unordered_map<int, int> record; // num -> index
        for (int i = 0;i < nums.size();i++) {
            int num = nums[i];
            auto it = record.find(num);
            if (it == record.end()) {
                record[num] = i;
            } else {
                if (it->second + 1 == i) {
                    record[num] = i;
                } else {
                    // 寻找并交换
                    while (it->second + 1 < i) {
                        int tmp = nums[it->second + 1];
                        if (record.find(tmp)->second + 1 == i) {
                            record.find(tmp)->second = i; // 更新被交换元素的最后一个index
                        }
                        nums[it->second + 1] = it->first; // 重要
                        nums[i] = tmp;
                        it->second = it->second + 1; // 更新最后一个index
                        it = record.find(nums[i]); // next iterator
                    }
                }
            }
        }
    }
    enum Color {
        RED,
        WHITE,
        BLUE
    };

    void sortColors_poor(std::vector<int>& nums) {
        int index_red = -1;
        int index_white = -1;
        int index_blue = -1;
        // 保证 index_red < index_white < index_blue
        for (int i = 0; i < nums.size(); i++) {
            int color = nums[i];
            switch (color) {
                case Color::RED:
                    if (index_red == -1) index_red = i;
                    else {
                        // swap
                        if (index_red == i - 1) {
                            index_red = i;
                        } else {
                            // 
                        }
                    }
                    break;
                case Color::WHITE:
                    if (index_white == -1) index_white = i;
                    else {
                        // swap
                        if (index_white == i - 1) {
                            index_white = i;
                        } else {

                        }
                    }
                    break;
                case Color::BLUE:
                    if (index_blue == -1) index_blue = i;
                    else {
                        // swap
                        if (index_blue == i - 1) {
                            index_blue = i;
                        } else {

                        }
                    }
                    break;
            }
        }
    }

    void sortColors(std::vector<int>& nums) { // p_0 指向尾指针
        int p_0 = 0;
        int p_1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int color = nums[i];
            if (color == 1) {
                std::swap(nums[i], nums[p_1]);
                p_1++;
            } else if (color == 0) { // p_1 指向
                std::swap(nums[i], nums[p_0]);
                if (p_0 < p_1) {
                    std::swap(nums[i], nums[p_1]);
                }
                p_0++;
                p_1++;
            }
        }
    }
};

int main() {
    std::vector<int> nums{2,0,0,2,0,1,2,1,0};
    Solution().sortColors_not_answer(nums);
    for (auto num: nums) {
        printf("%d ", num);
    }
    printf("\n");
}