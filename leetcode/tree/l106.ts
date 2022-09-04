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


function buildTree(inorder: number[], postorder: number[]): TreeNode | null {
    return helper(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
};

function helper(inorder: number[], postorder: number[]
    , inStart: number, inEnd: number
    , posStart: number, posEnd: number): TreeNode | null {
    console.log(posStart, posEnd, inStart, inEnd);
    if (posStart > posEnd || inStart > inEnd) return null;
    let root = new TreeNode(postorder[posEnd]);
    let rootIdx = inorder.indexOf(root.val);
    root.left = helper(inorder, postorder
        , inStart, rootIdx - 1
        , posStart, posStart + rootIdx - 1 - inStart);
    root.right = helper(inorder, postorder
        , rootIdx + 1, inEnd
        , posEnd - (inEnd - rootIdx), posEnd - 1
    );
    return root;
}

buildTree([9, 3, 15, 20, 7], [9, 15, 7, 20, 3]);