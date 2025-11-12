#include "leetcode.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

class Solution0 {
public:
    // O(NlogN)
    int longestConsecutive_N_Log_N(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // 先排序
        std::sort(nums.begin(), nums.end());
        // 再统计
        int max_sequence = 0;
        int cur_sequence = 1;
        for (int i = 1; i <= nums.size() - 1; i++) { // look back
            if (nums[i] - nums[i-1] == 1) {
                cur_sequence++;
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                max_sequence = std::max(cur_sequence, max_sequence);
                cur_sequence = 1;
            }
        }
        return std::max(cur_sequence, max_sequence);
    }

    // 寻找当前节点是否为可能存在子序列的开始节点
    // 这样就只会尝试遍历所有的子序列 以及 每个节点
    // n + n
    int longestConsecutive_1(std::vector<int>& nums) {
        std::unordered_set<int> num_set {nums.begin(), nums.end()};
        int sequence = 0;
        for (auto num : num_set) {
            if (num_set.count(num - 1) != 0) {
                continue;
            }
            // 以num为开头的节点
            // num 肯定在num_set中
            auto next = num + 1;
            while (num_set.count(next) > 0) next++;
            // next - 1 为最终值
            sequence = std::max(sequence, next - num);
        }
        return sequence;
    }



};


class UnionFind {
private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> size;
public:
    void add(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            size[x] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩，parent[x] 指向同一个root
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) { // 合并
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }

    int getMaxSize() {
        int maxSize = 0;
        for (auto& [key, val]: size) {
            maxSize = std::max(maxSize, val);
        }
        return maxSize;
    }
};
class Solution {
        // 并查集
    // 
    int longestConsecutive_uf(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        UnionFind uf;
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num: numSet) {
            uf.add(num);
        }
        for (int num: numSet) {
            if (numSet.count(num+1)) {
                uf.unite(num, num+1);
            }
        }
        return uf.getMaxSize();
    }

    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int max = 0;
        for (auto num: numSet) {
            if (numSet.count(num - 1) != 0) continue;
            int next = num + 1;
            while (numSet.count(next) > 0) {
                next++;
            }
            max = std::max(max, next - num);
        }
        return max;
    }
};
