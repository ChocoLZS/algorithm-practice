#include <vector>

class Solution {
public:
    void rotate_shell(std::vector<std::vector<int>>& matrix, int start, int end) {
        int n = end - start;
        // top -> right matrix[start+i][end] = matrix[start][start+i]
        // right -> bottom matrix[end][end-i] = matrix[start+i][end]
        // bottom -> left matrix[end-i][start] = matrix[end][end-i]
        // left -> top matrix[start][start+i] = matrix[end-i][start]
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            // rotate 4
            tmp = matrix[start][start+i];
            matrix[start][start+i] = matrix[end-i][start];
            matrix[end-i][start] = matrix[end][end-i];
            matrix[end][end-i] = matrix[start+i][end];
            matrix[start+i][end] = tmp;
        }
    }
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int shell_counts = n >> 1;
        for (int shell = 0; shell < shell_counts; shell++) {
            rotate_shell(matrix, 0 + shell, n - 1 - shell);
        }
    }
};