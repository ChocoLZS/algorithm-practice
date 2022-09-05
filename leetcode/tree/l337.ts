function rob(root: TreeNode | null): number {
    let leftMax = 0;
    let leftIndex = -1;
    let rightMax = 0;
    let rightIndex = -1;
    const dfs = (root: TreeNode | null, level: number) => {
        if (root == null) return;
        if (level % 2 == 0) {
            evenRes += root.val;
        } else {
            oddRes += root.val;
        }
        dfs(root.left, level + 1);
        dfs(root.right, level + 1);
    }
    dfs(root, 0);
    return Math.max(oddRes, evenRes);
};