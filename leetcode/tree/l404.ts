function sumOfLeftLeaves(root: TreeNode | null): number {
    let res = 0;
    const dfs = (node: TreeNode | null, tag) => {
        if (!node) return;
        if (node.left == null && node.right == null) {
            if (tag == 0)
                res += node.val;
            else if (tag == 1)
                return;
        }
        dfs(node.left, 0);
        dfs(node.right, 1);
    }
    dfs(root, -1);
    return res;
};