class Node {
    val: number
    children: Node[]
    constructor(val?: number) {
        this.val = (val === undefined ? 0 : val)
        this.children = []
    }
}


function levelOrder(root: Node | null): number[][] {
    let queue = [] as Array<[Node, number]>;
    let res = [];
    if (root == null) return res;
    queue.push([root, 0]);
    while (queue.length != 0) {
        let [node, level] = queue.shift() as [Node, number];
        if (res[level] !== undefined)
            res[level] = res[level].concat([node.val]);
        else
            res[level] = [node.val];
        for (let child of node.children) {
            if (child != null) {
                queue.push([child, level + 1]);
            }
        }
    }
    return res;
};