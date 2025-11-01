#include <cstdio>
#include <vector>

class Solution {
public:
    enum Direction {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    static std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        Direction direction = Direction::RIGHT;
        int border_right = matrix[0].size() - 1;
        int border_down = matrix.size() - 1;
        int border_left = 0;
        int border_up = 0;
        int row = 0, col = 0;
        while ((border_right - border_left) != 0 || (border_down - border_up) != 0) {
            printf("row,col=(%d,%d) direction=%d\n", row,col,direction);
            printf("left:%d up:%d right:%d down: %d\n", border_left, border_up, border_right, border_down);
            switch (direction) {
                case Direction::RIGHT:
                    while (col <= border_right) {
                        res.push_back(matrix[row][col]);
                        col++;
                    }
                    col = col-1;
                    row++;
                    if (border_up < border_down)
                        border_up++;
                    direction = Direction::DOWN;
                    break;
                case Direction::DOWN:
                    while (row <= border_down) {
                        res.push_back(matrix[row][col]);
                        row++;
                    }
                    row = row - 1;
                    col--;
                    if (border_right > border_left)
                        border_right--;
                    direction = Direction::LEFT;
                    break;
                case Direction::LEFT:
                    while (col >= border_left) {
                        res.push_back(matrix[row][col]);
                        col--;
                    }
                    col = col + 1;
                    row--;
                    if (border_down > border_up)
                        border_down--;
                    direction = Direction::UP;
                    break;
                case Direction::UP:
                    while (row >= border_up) {
                        res.push_back(matrix[row][col]);
                        row--;
                    }
                    row = row + 1;
                    col++;
                    if (border_left < border_right)
                        border_left++;
                    direction = Direction::RIGHT;
                    break;
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> matrix {{{1,2,3},{4,5,6},{7,8,9}}};
    auto res = Solution::spiralOrder(matrix);
    for (auto num: res) {
        printf("%d ", num);
    }
}