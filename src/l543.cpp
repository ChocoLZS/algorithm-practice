#include "leetcode.hpp"
#include <algorithm>
#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
/**
 * 左返回合并最长路径，右返回单边最长路径
*/
    std::pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return std::make_pair(0, -1);
        auto [left_merged, left_single] = dfs(node->left);
        auto [right_merged, right_single] = dfs(node->right);
        int max_merged = std::max(std::max(left_merged, right_merged), left_single + right_single + 2);
        return std::make_pair(max_merged, std::max(left_single, right_single) + 1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        auto [merged, _] = dfs(root);
        return merged;
    }
};