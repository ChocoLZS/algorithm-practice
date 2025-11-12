#include <algorithm>
#include <vector>

class Solution_normal {
public:
    int binarySearch(std::vector<int>& line, int target) {
        int left = 0;
        int right= line.size() - 1;
        int middle = (left + right) >> 1;
        while (left <= right) {
            middle = (left + right) >> 1;
            if (line[middle] == target) return middle;
            if (line[middle] > target) right = middle - 1;
            if (line[middle] < target) left = middle + 1;
        }
        return -1;
    }

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        bool result = false;
        for (int i = 0;i < matrix.size() && result == false;i++) {
            if (binarySearch(matrix[i], target) >= 0) {
                result = true;
            }
        }
        return result;
    }
};


class Solution {
public:

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        bool result = false;
        int x = 0, y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0 && result == false) {
            int num = matrix[x][y];
            if (num > target) y = y-1;
            else if (num < target) x = x+1;
            else result = true;
        }
        return result;
    }
};

// 将矩阵二维展开一维
class Solution_official {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];
            if (x < target) {
                low = mid + 1;
            } else if (x > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
