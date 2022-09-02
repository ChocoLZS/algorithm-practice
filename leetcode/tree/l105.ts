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


function buildTree(preorder: number[], inorder: number[]): TreeNode | null {
    let root = new TreeNode(preorder[0]);

};

function buildLeft(root: TreeNode, preorder: number[], inorder: number[]) {

}
function buildRight(root: TreeNode, preorder: number[], inorder: number[]) {

}