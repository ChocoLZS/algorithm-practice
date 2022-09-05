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


// function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
//     let map = new Map<number, TreeNode>();
//     let resmap = new Map<number, TreeNode>();
//     const dfs = (node: TreeNode | null) => {
//         if (node == null) return;
//         if (!map.has(node.val)) {
//             map.set(node.val, node)
//         } else {
//             let curNode = map.get(node.val);
//             let curNodeCount = nodeCount(curNode);
//             let nodeC = nodeCount(node);
//             if (nodeC < curNodeCount) {
//                 map.set(node.val, node);
//             } else if (nodeC === curNodeCount) {
//                 if (isEqual(node, curNode)) {
//                     resmap.set(node.val, node);
//                 }
//             }
//         }
//         dfs(node.left);
//         dfs(node.right);
//     }
//     const isEqual = (nodeA: TreeNode | null, nodeB: TreeNode | null): boolean => {
//         if (nodeA === null && nodeB === null) return true;
//         if (nodeA !== null && nodeB !== null) {
//             return nodeA.val === nodeB.val && isEqual(nodeA.left, nodeB.left) && isEqual(nodeA.right, nodeB.right);
//         } else {
//             return false;
//         }

//     }
//     const nodeCount = (root: TreeNode | null) => {
//         let count = 0;
//         const helper = (node: TreeNode | null) => {
//             if (node == null) return;
//             count++;
//             helper(node.left);
//             helper(node.right);
//         }
//         helper(root);
//         return count
//     }
//     dfs(root);
//     const addSubTree = (node: TreeNode | null) => {
//         if (node == null) return;
//         if (!resmap.has(node.val)) {
//             resmap.set(node.val, node);
//         }
//         addSubTree(node.left);
//         addSubTree(node.right);
//     }
//     for (let [key, node] of resmap) {
//         addSubTree(node);
//     }
//     let arr = [];
//     for (let [key, node] of resmap) {
//         arr.push(node);
//     }
//     return arr;
// };

function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
    const firstmeet = new Map();
    const repeat = new Set();
    const dfs = (node) => {
        if (!node) {
            return '';
        }
        let str = '';
        str += node.val;
        str += "(";
        str += dfs(node.left);
        str += ")(";
        str += dfs(node.right);
        str += ")";
        if (!firstmeet.has(str)) {
            firstmeet.set(str, node);
        } else {
            repeat.add(firstmeet.get(str));
        }
        return str;
    }
    dfs(root);
    return [...repeat];
}