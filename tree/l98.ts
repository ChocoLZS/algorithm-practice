// function isValidBST(root: TreeNode | null): boolean {
//     let queue = new Array<number>();
//     _buildQueue(root, queue);
//     let flag = true;
//     if (queue.length == 1)
//         return flag;
//     for (let i = 0; i < queue.length - 1) {
//         flag = flag && (queue[i] < queue[i + 1]);
//     }
//     return flag

// };

// function _buildQueue(node: TreeNode | null, queue: Array<number>) {
//     if (node == null) return;
//     _buildQueue(node.left, queue);
//     queue.push(node.val);
//     _buildQueue(node.right, queue);
// } 

function isValidBST(root: TreeNode | null): boolean {
    return helper(root, -Infinity, Infinity);
};

function helper(root: TreeNode | null, lower: number, upper: number): boolean {
    if (root == null) return true;
    if (root.val <= lower || root.val >= upper) return false;
    return helper(root.left, lower, root.val) && helper(root.right, root.val, upper);
}