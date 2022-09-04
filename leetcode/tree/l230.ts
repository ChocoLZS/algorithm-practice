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

function kthSmallest(root: TreeNode | null, k: number): number {
    let curEle;
    let n = 0;
    function helper(root: TreeNode | null, k: number) {
        if (n == k) return;
        if (root == null) return;
        helper(root.left, k);
        if (n != k) {
            curEle = root.val;
            n += 1;
        } else return;
        helper(root.right, k);
    }
    helper(root, k);
    return curEle;
};