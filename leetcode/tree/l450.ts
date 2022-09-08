function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root == null) return null;
    if (root.val == key) {
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;

    } else {

    }
    return root;
};

