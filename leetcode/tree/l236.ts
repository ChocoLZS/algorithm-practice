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


function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    let pStack = [];
    let qStack = [];
    helper(root, p, pStack);
    helper(root, q, qStack);
    if (pStack.length > qStack.length) {
        pStack = pStack.slice(0, qStack.length);
    } else if (pStack.length < qStack.length) {
        qStack = qStack.slice(0, pStack.length);
    }
    return getParent(pStack, qStack);
};

function helper(root: TreeNode | null, node: TreeNode | null, stack: TreeNode[]): boolean {
    if (root == null) return false;
    if (node == null) return false;
    stack.push(node.val)
    if (root.val == node.val) {
        return true;
    }
    let flag = false;
    flag = helper(root.left, node, stack);
    if (flag) {
        return true;
    }
    flag = helper(root.right, node, stack);
    if (flag) {
        return true;
    }
    stack.pop();
    return false;
}

function getParent(pStack: TreeNode[], qStack: TreeNode[]) {
    for (let i = pStack.length - 1; i >= 0; i--) {
        if (pStack[i] == qStack[i]) return pStack[i];
    }
}

