#include <vector>
// #include "leetcode.hpp"

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    // 此题中一定能找得到index，忽略异常处理
    int find(std::vector<int>& nums, int target) {
        int index = 0;
        while (index < nums.size() && nums[index] != target) index++;
        return index;
    }
public:
    TreeNode* buildTree_inner_bad(std::vector<int>& preorder, std::vector<int>& inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
        if (preorder_start > preorder_end || inorder_start > inorder_end) return nullptr;
        if (preorder_start >= preorder.size() || preorder_end < 0) return nullptr;
        if (inorder_start >= inorder.size() || inorder_end < 0) return nullptr;
        int node_val = preorder[preorder_start];
        TreeNode* node = new TreeNode(node_val);
        // find index
        int index_in_inorder = find(inorder, node_val);
        if (index_in_inorder == inorder_start) {
            node->left = nullptr;
            // handle right child
            node->right = buildTree_inner(preorder, inorder, preorder_start + 1, preorder_end, index_in_inorder + 1, inorder_end);
        } else {
            int index_left_end = find(preorder, inorder[index_in_inorder - 1]);
            node->left = buildTree_inner(preorder, inorder, preorder_start + 1, index_left_end, inorder_start, index_in_inorder - 1);
            node->right = buildTree_inner(preorder, inorder, index_left_end + 1, preorder_end, index_in_inorder + 1, inorder_end);
        }
        return node;
    }
    std::unordered_map<int, int> inorder_map;  // 值 -> 索引 // 减少查询速度
        TreeNode* buildTree_inner(const std::vector<int>& preorder, 
                             const std::vector<int>& inorder, 
                             int preorder_start, int preorder_end, 
                             int inorder_start, int inorder_end) {
        // 边界条件
        if (preorder_start > preorder_end) return nullptr;
        
        // 前序遍历的第一个元素是根节点
        int root_val = preorder[preorder_start];
        TreeNode* root = new TreeNode(root_val);
        
        // 在中序遍历中找到根节点的位置
        int index_in_inorder = inorder_map[root_val];
        
        // 计算左子树的大小
        int left_tree_size = index_in_inorder - inorder_start;
        
        // 递归构建左右子树
        root->left = buildTree_inner(
            preorder, inorder,
            preorder_start + 1,                    // 左子树起点
            preorder_start + left_tree_size,       // 左子树终点
            inorder_start,                         // 左子树起点
            index_in_inorder - 1                   // 左子树终点
        );
        
        root->right = buildTree_inner(
            preorder, inorder,
            preorder_start + left_tree_size + 1,   // 右子树起点
            preorder_end,                          // 右子树终点
            index_in_inorder + 1,                  // 右子树起点
            inorder_end                            // 右子树终点
        );
        
        return root;
    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        // 先序是根，左子树，右子树，中序，左子树，根，右子树
        return buildTree_inner(preorder, inorder, 0, preorder.size() - 1, 0 , inorder.size() - 1);
    }
};

int main() {
    std::vector<int> preorder = {1,2,3};
    std::vector<int> inorder = {2,3,1};
    auto node = Solution().buildTree(preorder, inorder);
    
}