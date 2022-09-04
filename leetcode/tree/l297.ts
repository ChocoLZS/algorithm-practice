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

function serialize(root: TreeNode | null): string {
    let ans = []: string[];
    const dfs = (node: TreeNode | null) => {
        if (node == null) {
            ans.push('null');
            return;
        }
        ans.push(node.val.toString());
        dfs(node.left);
        dfs(node.right);
    }
    dfs(root);
    return ans.join(',');
};

/*
 * Decodes your encoded data to tree.
 */
function deserialize(data: string): TreeNode | null {
    if (data == '') return null;
    const arr = data.split(',');
    if (arr[0] == 'null') return null;
    let index = 0;
    const dfs = (): TreeNode | null => {
        const str = arr[index++];
        if (val == 'null') return null;
        let node = new TreeNode(Number.parseInt(val));
        node.left = dfs();
        node.right = dfs();

        return node;
    }
    return dfs();
};


///*
// * Encodes a tree to a single string.
// */
//function serialize(root: TreeNode | null): string {
//    let arr = [] as Array<TreeNode | null>;
//    let queue = [] as Array<TreeNode | null>;
//    if (root == null) return '[]';
//    queue.push(root);
//    while (queue.length != 0) {
//        let curNode = queue.shift() as TreeNode | null;
//        if (curNode != null) {
//            queue.push(curNode.left);
//            queue.push(curNode.right);
//        }
//        arr.push(curNode);
//    }
//    let middle = ''
//    let i = 0;
//    for (i = 0; i < arr.length - 1; i++) {
//        middle = middle + nodeToString(arr[i]) + ',';
//    }
//    middle = middle + nodeToString(arr[i]);
//    return '[' + middle + ']'
//};
//
//function nodeToString(node: TreeNode | null): string {
//    return node == null ? 'null' : node.val.toString();
//}
//
///*
// * Decodes your encoded data to tree.
// */
//function deserialize(data: string): TreeNode | null {
//    let middle = data.substring(1, data.length - 1);
//    if (middle === '') return null;
//    let nums = middle.split(',');
//    let queue = [];
//    let i = 0;
//    let str = nums.shift();
//    let root = strToNode(str as string);
//    queue.push(root);
//    do {
//        let curNode = queue.shift() as TreeNode | null;
//
//        if (curNode === null) continue;
//
//        str = nums.shift();
//        if (str === undefined) break;
//        let leftChild = strToNode(str);
//
//        str = nums.shift();
//        if (str === undefined) break;
//        let rightChild = strToNode(str);
//
//        curNode.left = leftChild;
//        curNode.right = rightChild;
//        queue.push(leftChild);
//        queue.push(rightChild);
//    } while (true);
//    return root;
//};
//
//function strToNode(str: string): TreeNode | null {
//    return str.match('null') ? null : new TreeNode(Number.parseInt(str));
//}
//
//
///**
// * Your functions will be called as such:
// * deserialize(serialize(root));
// */
//