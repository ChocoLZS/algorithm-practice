function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root == null) return null;
    if (root.val == key) {
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;
        let preNode = root;
        let curNode = root.right;
        while (curNode.left !== null) {
            preNode = curNode;
            curNode = curNode.left;
        }
        if (preNode.val === root.val) {
            curNode.left = root.left;
        } else {
            preNode.left = curNode.right;
            curNode.left = root.left;
            curNode.right = root.right;
        }
        return curNode;
    } else {
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
        } else {
            root.right = deleteNode(root.right, key);
        }
    }
    return root;
};

