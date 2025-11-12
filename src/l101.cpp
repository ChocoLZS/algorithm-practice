#include <leetcode.hpp>
#include <queue>

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
    // recursive
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    bool isMirror_iterator(TreeNode* root) {
        bool result = true;
        std::queue<TreeNode*> left_q;
        std::queue<TreeNode*> right_q;
        left_q.push(root->left);
        right_q.push(root->right);
        while (!left_q.empty() && !left_q.empty() && result) {
            auto left_node = left_q.front();
            auto right_node = right_q.front();

            if (left_node == nullptr && right_node == nullptr) {
                // pass
            } else if (left_node == nullptr || right_node == nullptr) {
                result = false;
            } else {
                if (left_node->val != right_node->val) result = false;
                left_q.push(left_node->left);
                right_q.push(right_node->right);
                left_q.push(left_node->right);
                right_q.push(right_node->left);
            }
            left_q.pop();
            right_q.pop();
            
        }
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        // return isMirror(root->left, root->right);
        return isMirror_iterator(root);
    }
};