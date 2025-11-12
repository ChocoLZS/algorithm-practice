#include "leetcode.hpp"
#include <vector>
#include <queue>
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
    std::vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        // 层序遍历的最后一个
        std::vector<int> rightViews{};
        std::queue<std::pair<TreeNode*, int>> q;
        std::pair<TreeNode*, int> pre = {nullptr, -1};
        TreeNode* curr = nullptr;
        q.push({root, 0});
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            if (top.first == nullptr) {
                continue;
            }
            if (pre.first != nullptr && top.second > pre.second) {
                rightViews.push_back(pre.first->val);
            }
            pre = top;
            curr = top.first;
            q.push({top.first->left, top.second + 1});
            q.push({top.first->right, top.second + 1});
        }
        rightViews.push_back(curr->val);
        return rightViews;
    }
};