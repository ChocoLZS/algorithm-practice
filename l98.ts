function isValidBST(root: TreeNode | null): boolean {
    let queue = new Array<number>();
    _buildQueue(root, queue);
    let flag = true;
    if (queue.length == 1)
        return flag;
    for (let i = 0; i < queue.length - 1) {
        flag = flag && (queue[i] < queue[i + 1]);
    }
    return flag

};

function _buildQueue(node: TreeNode | null, queue: Array<number>) {
    if (node == null) return;
    _buildQueue(node.left, queue);
    queue.push(node.val);
    _buildQueue(node.right, queue);
} 