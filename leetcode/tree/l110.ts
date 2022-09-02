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


function isBalanced(root: TreeNode | null): boolean {
    if (root == null) return true
    return helper(root) && isBalanced(root?.left) && isBalanced(root?.right);
};

function helper(root: TreeNode | null): boolean {
    return Math.abs(calcHeight(root?.left, 1) - calcHeight(root?.right, 1)) <= 1;
}

function calcHeight(root: TreeNode | null, level: number): number {
    if (root == null) return level - 1;
    return Math.max(calcHeight(root.left, level + 1), calcHeight(root.right, level + 1));
}