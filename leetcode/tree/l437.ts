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


function pathSum(root: TreeNode | null, targetSum: number): number {
    const prefixMap = new Map();
    prefixMap.set(0, 1);
    return dfs(root, prefixMap, 0, targetSum);
};

function dfs(node: TreeNode | null, prefixMap: Map, curr: number, targetSum: number) {
    if (node == null) {
        return 0;
    }
    let res = 0;
    curr += node.val;
    res = prefixMap.get(curr - targetSum) || 0;
    prefixMap.set(curr, (prefixMap.get(curr) || 0) + 1);
    res += dfs(node.left, prefixMap, curr, targetSum);
    res += dfs(node.right, prefixMap, curr, targetSum);
    prefixMap.set(curr, (prefixMap.get(curr) || 0) - 1);
    return res;
}
