function pathSum(root: TreeNode | null, targetSum: number): number {
    let prefix = new Map<number, number>();
    prefix.set(0, 1);
    const dfs = (node, cur) => {
        if (node == null) return 0;
        let res = 0;
        cur += node.val;
        res = prefix.get(cur - targetSum) || 0;
        return res;
    }
    return
};