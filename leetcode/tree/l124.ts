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

function maxPathSum(root: TreeNode | null): number {
    let max = -Infinity;
    function helper(root: TreeNode | null): number {
        if (root == null) return -Infinity;
        let leftMax = helper(root.left);
        let rightMax = helper(root.right);
        let ans = 0;
        if (leftMax >= 0) ans += leftMax;
        if (rightMax >= 0) ans += rightMax;
        max = Math.max(max, ans + root.val);
        let _max = Math.max(leftMax, rightMax);
        return root.val + (_max >= 0 ? _max : 0);
    }
    helper(root);
    return max;
};

