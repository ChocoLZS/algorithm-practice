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


function sumNumbers(root: TreeNode | null): number {
    let res = 0;
    function helper(root: TreeNode | null, preNum: number) {
        if (root == null) return;
        preNum = preNum * 10 + root.val;
        if (root.left == null && root.right == null) {
            res += preNum;
        } else {
            helper(root.left, preNum);
            helper(root.right, preNum);
        }
    }
    helper(root, 0);
    return res;
};