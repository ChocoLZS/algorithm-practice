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


function zigzagLevelOrder(root: TreeNode | null): number[][] {
    let res_node = new Array<Array<TreeNode>>();
    let queue = new Array<TreeNode>();
    let level = 0;
    if (root !== null) queue.push(root);
    while (queue.length !== 0) {
        res_node[level] = queue;
        let new_queue = [];
        res_node[level].forEach(v => {
            v.left !== null ? new_queue.push(v.left) : '';
            v.right !== null ? new_queue.push(v.right) : '';
        })
        queue = new_queue;
        level++;
    }
    return res_node.map((v, idx) => {
        let arr = [];
        if (idx % 2 == 0) {
            for (let node of v) {
                arr.push(node.val);
            }
        } else {
            for (let index = v.length - 1; index >= 0; index--) {
                arr.push(v[index].val);
            }
        }

        return arr
    });
};