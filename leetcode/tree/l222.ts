
function countNodes(root: TreeNode | null): number {
    if (root == null) return 0;
    let lheight = 0;
    let rheight = 0;
    let pNode = root?.left;
    while (pNode != null) {
        lheight++;
        pNode = pNode?.left;
    }
    pNode = root?.right;
    while (pNode != null) {
        rheight++;
        pNode = pNode?.right;
    }
    if (lheight == rheight) {
        return Math.pow(2, lheight + 1) - 1;
    }
    return dfs(root.left) + dfs(root.right) + 1;
};