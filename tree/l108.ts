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


function sortedArrayToBST(nums: number[]): TreeNode | null {
    return helper(nums, 0, nums.length - 1)
};
function helper(nums: number[], startIndex: number, endIndex: number): TreeNode | null {
    if (startIndex > endIndex) return null;
    let middleIndex = Math.floor((endIndex - startIndex) / 2) + startIndex;
    let root = new TreeNode(nums[middleIndex]);
    root.left = helper(nums, startIndex, middleIndex - 1);
    root.right = helper(nums, middleIndex + 1, endIndex);

    return root;
}
