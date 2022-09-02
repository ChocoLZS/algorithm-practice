class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


function hasPathSum(root: TreeNode | null, targetSum: number): boolean {
    let flag = false;
    function helper(node: TreeNode | null, curSum: number, targetSum: number) {
        if (flag) return;
        if (node == null) return;
        if (curSum + node.val > targetSum) return;
        if (node.left == null && node.right == null curSum + node.val == targetSum) {
            flag = true;
            return;
        }
        helper(node.left, curSum + node.val, targetSum);
        helper(node.right, curSum + node.val, targetSum);
    }
    helper(root, 0, targetSum);
    return flag;
};