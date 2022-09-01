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

//  recursive

// function inorderTraversal(root: TreeNode | null): number[] {
//     let arr = [] as number[]
//     _inorder(root, arr);
//     return arr
// };

// function _inorder(root: TreeNode | null, arr: number[]) {
//     if (root === null) return;
//     _inorder(root.left, arr);
//     arr.push(root.val);
//     _inorder(root.right, arr);
// }

function inorderTraversal(root: TreeNode | null): number[] {
    let arr = [] as number[]
    let stack = [] as TreeNode[]
    let node = root;
    while (node !== null || stack.length !== 0) {
        if (node !== null) {
            stack.push(node);
            node = node.left;
        } else {
            node = stack.pop();
            arr.push(node?.val);
            node = node?.right;
        }
    }
    return arr
}   