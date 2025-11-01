#include "leetcode.hpp"
#include <queue>
#include <utility>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<std::pair<int, TreeNode*>> node_q;
        std::vector<std::vector<int>> res;
        node_q.push({1, root});
        while (!node_q.empty()) {
            auto [level, node] = node_q.front();
            node_q.pop();
            if (node == nullptr) continue;
            if (res.size() < level) res.push_back(std::vector<int>{});
            res[level - 1].push_back(node->val);
            node_q.push({level+1, node->left});
            node_q.push({level+1, node->right}); 
        }
        return res;
    }
};