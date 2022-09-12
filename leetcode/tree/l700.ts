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


function searchBST(root: TreeNode | null, val: number): TreeNode | null {
    let node = root;
    while (node !== null && node.val !== val) {
        node = node.val > val ? node.left : node.right;
    }
    return node.val === val;
};