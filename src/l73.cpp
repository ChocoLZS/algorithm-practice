#include <utility>
#include <vector>

class Solution {
public:

    void setZero(std::vector<std::vector<int>>& matrix, int row, int col) {
        int index = 0;
        // left
        index = col - 1;
        while (index >= 0) {
            matrix[row][index] = 0;
            index--;
        }
        // up
        index = row - 1;
        while (index >= 0) {
            matrix[index][col] = 0;
            index--;
        }
        // right
        index = col + 1;
        while (index <= matrix[0].size() - 1) {
            matrix[row][index] = 0;
            index++;
        }
        // down
        index = row + 1;
        while (index <= matrix.size() - 1) {
            matrix[index][col] = 0;
            index++;
        }
    }
    // 方法1，记录原始为0的坐标，然后根据这些坐标置零
    void setZeroes_poor(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> record{};
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size();j++) {
                if (matrix[i][j] == 0){
                    record.push_back({i,j});
                }
            }
        }
        for (auto p : record) {
            int row = p.first;
            int col = p.second;
            setZero(matrix, row, col);
        }
    }
    // 方法2，如果行出发，那么同一行的0不用触发行
    // 如果列出发，同一列的0不用触发列
    //
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        bool is_zero_row = false;
        bool is_zero_col = false;
        for (int i = 0; i < matrix.size();i++) {
            if (matrix[i][0] == 0) {
                is_zero_row = true;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size();j++) {
            if (matrix[0][j] == 0) {
                is_zero_col = true;
                break;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size();j++) {
                if (matrix[i][j] == 0){ // trigger
                    matrix[0][j] = 0;
                    matrix[i][0] = 0; // 将其对应的行/列第一个元素标记为0
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                // 整行为0
                for (int j = 1; j < matrix[0].size();j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size();j++) {
            if (matrix[0][j] == 0) {
                // 整列为0
                for (int i = 1; i < matrix.size();i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (is_zero_row) {
            for (int i = 0; i < matrix.size();i++) {
                matrix[i][0] = 0;
            }
        }
        if (is_zero_col) {
            for (int j = 0; j < matrix[0].size();j++) {
                matrix[0][j] = 0;
            }
        }
    }
};