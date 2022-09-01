function generateTrees(n: number): Array<TreeNode | null> {
    return _generateTrees(1, n)
};

function _generateTrees(start: number, end: number): Array<TreeNode | null> {
    let arr = new Array<TreeNode | null>();

    if (start > end) {
        arr.push(null);
        return arr;
    }

    for (let i = start; i <= end; i++) {
        let left_arr = _generateTrees(start, i - 1);
        let right_arr = _generateTrees(i + 1, end);
        for (let left_node of left_arr) {
            for (let right_node of right_arr) {
                let node = new TreeNode(i, left_node, right_node);
                arr.push(node);
            }
        }
    }
    return arr;
}