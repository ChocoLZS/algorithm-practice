function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function (root, val, depth) {
    if (depth == 1) {
        let newRoot = new TreeNode(val);
        newRoot.left = root;
        return newRoot;
    }
    let level = 1;
    let queue = [];
    queue.push(root);
    while (level != depth - 1) {
        let qLen = queue.length;
        for (let i = 0; i < qLen; i++) {
            let curNode = queue.shift();
            if (curNode.left !== null) queue.push(curNode.left);
            if (curNode.right !== null) queue.push(curNode.right);
        }
        level++;
    }
    for (let node of queue) {
        let lchlid = new TreeNode(val);
        lchlid.left = node.left;
        node.left = lchlid;
        let rchild = new TreeNode(val);
        rchild.right = node.right;
        node.right = rchild;
    }
    return root;
};