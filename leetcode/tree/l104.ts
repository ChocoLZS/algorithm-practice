/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function maxDepth(root: TreeNode | null): number {
    let max = 0;
    function helper(node: TreeNode | null, level: number) {
        if (node == null) return;
        max = level > max ? level : max;
        helper(node.left, level + 1);
        helper(node.right, level + 1);
    }
    helper(root, 1);
    return max;
};
