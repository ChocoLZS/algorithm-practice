#include "leetcode.hpp"
#include <vector>
#include <stack>

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
    typedef TreeNode* ResultNode;
    // 中序遍历构造
    // 递归，分一半，中间节点为 middle
    // std::vector<int>& ,int start,int end
    TreeNode* createBST_recursive(std::vector<int>& nums, int start, int end) {
        // 
        if (start > end) return nullptr;
        int middle = (start + end) >> 1;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = createBST_recursive(nums, start, middle - 1);
        node->right = createBST_recursive(nums, middle + 1, end);
        return node;
    }
    // 迭代，使用栈的思想？
    // 层序遍历，是队列
    ResultNode createBST_iterator(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;
        struct Task {
            int start, end;
            ResultNode* node_ptr;
        };
        std::stack<Task> stk;
        ResultNode root = nullptr;
        stk.push({0, (int)nums.size() - 1, &root});
        while (!stk.empty()) {
            Task task = stk.top(); stk.pop();
            if (task.start > task.end) continue;
            int middle = (task.start + task.end) >> 1;
            *task.node_ptr = new TreeNode(nums[middle]);
            stk.push({task.start, middle - 1, &(*task.node_ptr)->left});
            stk.push({middle + 1, task.end, &(*task.node_ptr)->right});

        }
        return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return createBST_recursive(nums, 0, nums.size() - 1);
    }
};