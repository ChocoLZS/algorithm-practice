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


function findClosestLeaf(root: TreeNode, k: number): number {
    if (root.left == null && root.right == null) return root.val;
    let set = new Set<Array<number>>();
    let findNode;
    const dfs = (node, key, path: Array<TreeNode>) => {
        if (node == null) return;
        path.push(node);
        if (node.val == key
            || (node.left == null && node.right == null)
        ) {
            let paths = [] as Array<number>
            for (let n of path) {
                paths.push(n.val);
            }
            if (node.val == key) {
                findNode = paths
                if (node.left == null && node.right == null) {
                    set.add(paths);
                }
            } else {
                set.add(paths);
            }
        }
        dfs(node.left, key, path);
        dfs(node.right, key, path);
        path.pop();
    }
    dfs(root, k, [])
    let min = Infinity;
    let minVal;
    for (let path of set) {
        if (path.includes(k)) {
            if (min > (path.length - findNode.length + 1)) {
                min = path.length - findNode.length + 1;
                minVal = path[path.length - 1];
            }
        } else {
            let commonIndex = commonStr(path, findNode);
            let cmp = path.slice(commonIndex + 1, path.length).length + findNode.slice(commonIndex).length
            if (min > cmp) {
                min = cmp;
                minVal = path[path.length - 1];
            }
        }
    }
    return minVal;
};

function commonStr(arr1: Array<any>, arr2: Array<any>): number {
    let lastIdx;
    arr2.forEach((v, idx) => {
        if (arr1.includes(v)) {
            lastIdx = idx;
        } else {
            return lastIdx;
        }
    })
    return lastIdx
}