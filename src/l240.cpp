#include <cstdio>
#include <vector>

class Solution {
public:
    enum BinaryFound {
        TooSmall = -3,
        TooBig = -2,
        NotFound = -1,
    };
    enum BinaryDirection {
        Horizontal = 0,
        Vertical = 1
    };
    /**
    * direction: 0 代表横向，1 代表纵向
    * -1 代表未找到
    * -2 代表大于最大值
    * -3 代表小于最小值
    */
    int binarySearch(std::vector<std::vector<int>>& matrix, int target, int selected_line, int start, int end, BinaryDirection direction) {
        int middle = -1;
        int left = start, right = end;
        if (direction == BinaryDirection::Horizontal) {
            if (target < matrix[selected_line][left]) return BinaryFound::TooSmall;
            if (target > matrix[selected_line][right]) return BinaryFound::TooBig;
            while (left <= right) {
                middle = (left + right) >> 1;
                if (matrix[selected_line][middle] < target) {
                    left = middle + 1;
                } else if (matrix[selected_line][middle] > target) {
                    right = middle - 1;
                } else {
                    return middle;
                }
            }
            return matrix[selected_line][middle] < target ? left - 1 : right; // left == right 了，要找偏小的一个
        } else {
            if (target < matrix[left][selected_line]) return BinaryFound::TooSmall;
            if (target > matrix[right][selected_line]) return BinaryFound::TooBig;
            while (left <= right) {
                middle = (left + right) >> 1;
                if (matrix[middle][selected_line] < target) {
                    left = middle + 1;
                } else if (matrix[middle][selected_line] > target) {
                    right = middle - 1;
                } else {
                    return middle;
                }
            }
            return matrix[selected_line][middle] < target ? left - 1 : right; // left == right 了，要找偏小的一个
        }
        return BinaryFound::NotFound;
    }

    bool searchMatrix_sophisiticated(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        // 从第一行开始找
        int first_line_result = binarySearch(matrix, target, 0, 0, cols, BinaryDirection::Horizontal);
        printf("first_line_result: %d", first_line_result);
        if (first_line_result == BinaryFound::TooSmall) return false;
        if (first_line_result == BinaryFound::TooBig) { // 太大了，往下找
            // 往下找
            int second_times_result = binarySearch(matrix, target, cols, 0, rows, BinaryDirection::Vertical);
            printf("second_times_result: %d", second_times_result);
            if (second_times_result == BinaryFound::TooBig) return false;
            if (second_times_result < 0) return false;
            if (matrix[second_times_result][cols] == target) return true;
            // 不可能太小，肯定夹在中间
            // 左侧四宫格查找
            // 目前是
            int row = second_times_result + 1, col = cols - 1;
            // 循环找
            printf("col: %d\n", col);
            for(;col >= 0 && matrix[row][col] >= target;col--) {
                if (matrix[row][col] == target) return true;
            }
            return false;

        } else if (first_line_result >= 0) {
            printf("first_times_result: %d", first_line_result);
            // 返回中间值
            if (matrix[0][first_line_result] == target) return true;
            // 往下找
            int second_times_result = binarySearch(matrix, target, first_line_result, 0, rows, BinaryDirection::Vertical);
            printf("second_times_reault: %d, first_times_result: %d", second_times_result, first_line_result);
            if (second_times_result == BinaryFound::TooBig) return false;
            if (second_times_result < 0) return false;
            if (matrix[second_times_result][first_line_result] == target) return true;
            int row = second_times_result+1, col = first_line_result;
            printf("row: %d\n", row);
            for(;row <= rows && matrix[row][col] >= target;row++) {
                if (matrix[row][col] == target) return true;
            }
            return false;
        }
        
        return false;
    }

    // 又陷入了非常规解法的陷阱

    // 先想朴素方法, 遍历，m*n
    // 然后优化，每行二分，m*logn
    // 最后再找最优，官方题解，从右上开始，往左下缩小查找
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        int left = 0, bottom = m - 1;
        while (x <= bottom && y >= left) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                y--;
            } else if (matrix[x][y] < target) {
                x++;
            }
            
        }
        return false;
    }

    
};

int main() {
    // std::vector<std::vector<int>> matrix = {
    //     {1,4,7,11,15},
    //     {2,5,8,12,19},
    //     {3,6,9,16,22},
    //     {10,13,14,17,24},
    //     {18,21,23,26,30}
    // };
        // auto result = Solution().searchMatrix(matrix, 5);
    // std::vector<std::vector<int>> matrix = {
    //     {-5}
    // };
        // auto result = Solution().searchMatrix(matrix, -5);
    std::vector<std::vector<int>> matrix = {
       {2,5},
       {2,8},
       {7,9},
       {7,11},
       {9,11}
    };
    auto result = Solution().searchMatrix(matrix, 2);

    printf("%s", result ? "true" : "false");
}