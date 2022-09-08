function rob(root: TreeNode | null): number {
    let rootSelected = new Map();
    let rootNotSelected = new Map();
    const dfs = (node) => {
        if (!node) return;
        dfs(node.left);
        dfs(node.right);
        rootSelected.set(node, node.val
            + (rootNotSelected.get(node.left) || 0)
            + (rootNotSelected.get(node.right) || 0));
        rootNotSelected.set(node,
            (Math.max(rootSelected.get(node.left) || 0, rootNotSelected.get(node.left) || 0))
            + (Math.max(rootSelected.get(node.right) || 0, rootNotSelected.get(node.right) || 0))
        )
    }
    return Math.max(rootSelected.get(root), rootNotSelected.get(root));
};