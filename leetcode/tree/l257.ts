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


function binaryTreePaths(root: TreeNode | null): string[] {
    let res = [];
    function helper(root: TreeNode | null, arr: number[]) {
        if (root == null) return;
        arr.push(root.val);
        if (root.left == null && root.right == null) {
            let str = ''
            let i = 0;
            for (i = 0; i < arr.length - 1; i++) {
                str = str + arr[i] + '->';
            }
            str = str + arr[i];
            res.push(str);
            arr.pop();
            return;
        }
        helper(root.left, arr);
        helper(root.right, arr);
        arr.pop();
    }
    helper(root, []);
    return res;
};
