#include <queue>
#include <utility>
#include <vector>
#include <memory.h>
// #include <bit>

class UnionTree {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int counts;
public:
    explicit UnionTree(std::vector<std::vector<int>>& grid): parent(), rank(), counts(0) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    parent.push_back(row * cols + col);
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    };
};


class Solution {
    int count = 0;
    int dis[10][10];
    std::pair<int, int> direction[4] = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
public:
    // bfs, 多节点bfs，层序遍历
    // 辅助空间
    // count 计算未腐烂的橘子数量
    // dis来存放即将腐烂的橘子的步数
    // pair存放遍历的direction
    // queue 用于bfs层序遍历
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> index_q;
        memset(dis, -1, sizeof(dis));
        count = 0;
        int n = (int)grid.size(), m = (int)grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    index_q.push({i,j});
                    dis[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        while (!index_q.empty()) {
            auto [row, col] = index_q.front();
            index_q.pop();
            for (auto [delta_row, delta_col] : direction) {
                int row_t = row+delta_row;
                int col_t = col+delta_col;
                if (row_t < 0 || row_t >= n || col_t < 0 || col_t >= m || grid[row_t][col_t] == 0 || dis[row_t][col_t] >= 0) continue;
                dis[row_t][col_t] = dis[row][col] + 1;
                index_q.push({row_t,col_t});
                if (grid[row_t][col_t] == 1) {
                    count--;
                    ans = dis[row_t][col_t];
                    if (count == 0) break;
                }
            }
        }

        return count ? -1 : ans;
    }
};