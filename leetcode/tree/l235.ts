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

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    let pStack = helper(root, p);
    let qStack = helper(root, q);
    if (pStack.length > qStack.length) {
        pStack = pStack.slice(0, qStack.length);
    } else if (pStack.length < qStack.length) {
        qStack = qStack.slice(0, pStack.length);
    }
    return getParent(pStack, qStack);
};

function helper(root: TreeNode | null, node: TreeNode | null): TreeNode[] {
    if (node == null) return [];
    if (root == null) return [];
    let curNode = root;
    let res = [];
    while (curNode.val != node.val) {
        res.push(curNode);
        curNode = curNode.val > node.val ? curNode.left : curNode.right;
    }
    res.push(curNode);
    return res;
}

function getParent(pStack: TreeNode[], qStack: TreeNode[]) {
    for (let i = pStack.length - 1; i >= 0; i--) {
        if (pStack[i] == qStack[i]) return pStack[i];
    }
}

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    let parent = root;
    while (true) {
        if (p?.val < parent?.val && q?.val < parent?.val) {
            parent = parent?.left;
        } else if (p?.val > parent?.val && q?.val > parent?.val) {
            parent = parent?.right;
        } else {
            break;
        }
    }
    return parent;
};