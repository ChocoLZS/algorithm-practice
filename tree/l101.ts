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


function isSymmetric(root: TreeNode | null): boolean {
    return helper(root?.left, root?.right);
};

function helper(left: TreeNode | null, right: TreeNode | null): boolean {
    if (left == right) return true;
    if (left?.val !== right?.val) return false;
    return (
        helper(left?.left, right?.right)
        && helper(left?.right, right?.left)
    )
}

//queue

