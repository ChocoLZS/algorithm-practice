#include <cstddef>
#include <leetcode.hpp>

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
    // o(1) 原地
    // 先序，根 -> 左 -> 右
    // 那么就是 先访问每个根 先将左子树放在右边
    // 然后再处理左子树，
    // 最后回来将左子树（原右子树）放在右子树侧，同样处理 

    // 递归
    // root must not be nullptr
    // 但这样是o(n) ，有栈空间的损失
    TreeNode* flatten_recursive(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) return root;
        if (root->left == nullptr) {
            // flatten right
            return flatten_recursive(root->right);
        }
        if (root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
            return flatten_recursive(root->right);
        }
        // 如果两边都有
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        tmp = flatten_recursive(root->right);
        tmp->right = root->left;
        root->left = nullptr;
        return flatten_recursive(tmp->right);
    }

    // 先序遍历，寻找前驱节点
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                } 
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }

    }
};