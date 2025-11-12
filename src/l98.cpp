#include "leetcode.hpp"
#include <stack>
#include <cstdint>
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
    // 中序遍历，递增
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        // 迭代
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;
        long prev = INT64_MIN;
        bool result = true;
        while ((curr != nullptr || !stk.empty()) && result) {
            while (curr != nullptr) { // 压左
                stk.push(curr);
                curr = curr->left;
            }
            // 弹节点
            curr = stk.top();
            stk.pop();

            // do something
            result = curr->val > prev;
            prev = curr->val;
            curr = curr->right;
        }
        return result;
    }
};