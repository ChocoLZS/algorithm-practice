#include "leetcode.hpp"
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        std::vector<TreeNode*> node_stack;
        node_stack.push_back(root);
        while (!node_stack.empty()) {
            auto node = node_stack.back();
            node_stack.pop_back();
            if (node == nullptr) continue;
            node_stack.push_back(node->left);
            node_stack.push_back(node->right);
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }

        return root;
    }
};