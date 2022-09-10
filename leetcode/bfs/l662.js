/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var widthOfBinaryTree = function (root) {
    let lefts = []
    let rights = []
    function leftDfs(node, index, level) {
        if (node == null) return;

        leftDfs(node.left, index * 2, level + 1)
        leftDfs(node.right, index * 2 + 1, level + 1)
    }
    function rightDfs(node, index, level) {
        if (node == null) return 0;

        rightDfs(node.left, index * 2, level + 1)
        rightDfs(node.right, index * 2 + 1, level + 1)
    }
    leftDfs(root.left, 2, 1);
    rightDfs(root.right, 3, 1);
    let length = Math.min(lefts.length, rights.length);
    let max = 0;
    for (let i = 1; i < length; i++) {
        max = Math.max(max, lefts[i] + rights[i])
    }
    return max;
};