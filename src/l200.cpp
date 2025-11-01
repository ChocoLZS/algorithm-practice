#include <deque>
#include <utility>
#include <vector>
#include <queue>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;
public:
    UnionFind(std::vector<std::vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for ( int i = 0; i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    count++;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                std::swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }
};

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;
        int cols = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    grid[row][col] = '0';
                    if (row - 1 >= 0 && grid[row-1][col] == '1') uf.unite(row * cols + col, (row-1) * cols + col);
                    if (row + 1 < rows && grid[row+1][col] == '1') uf.unite(row * cols + col, (row+1) * cols + col);
                    if (col - 1 >= 0 && grid[row][col-1] == '1') uf.unite(row * cols + col, row * cols + col - 1);
                    if (col + 1 < cols && grid[row][col+1] == '1') uf.unite(row * cols + col, row * cols + col + 1);
                }
            }
        }

        return uf.getCount();
    }
};


class Solution {
public:

    void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
        // 向上，向左向右，向下
        std::deque<std::pair<int, int>> index_pair;
        index_pair.push_back({row, col});
        int top_boundary = 0, bottom_boundary = grid.size() - 1;
        int left_boundary = 0, right_boundary = grid[0].size() - 1;
        while (!index_pair.empty()) {
            auto pair = index_pair.front();
            index_pair.pop_front();
            auto x = pair.first;
            auto y = pair.second;
            if (x >= top_boundary && x <= bottom_boundary && y >= left_boundary && y <= right_boundary) {
                if (grid[x][y] != '0') {
                    // left
                    index_pair.push_back({x,y-1});
                    // top
                    index_pair.push_back({x-1,y});
                    // right
                    index_pair.push_back({x,y+1});
                    // bottom
                    index_pair.push_back({x+1,y});
                }
                grid[x][y] = '0';
            }
        }

    }
    // dfs, 深度优先// 这是bfs
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != '0') {
                    dfs(grid, row, col);
                    res++;
                }
            }
        }
        return res;
    }
};