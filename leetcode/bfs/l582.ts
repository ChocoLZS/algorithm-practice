class ProcessNode {
    val: number;
    childs: Array<ProcessNode>
    constructor(val?: number, childs?: Array<ProcessNode>) {
        this.val = val === undefined ? 0 : val;
        this.childs = childs === undefined ? [] : childs;
    }
}

function killProcess(pid: number[], ppid: number[], kill: number): number[] {
    let map = new Map<number, ProcessNode>();
    for (let _pid of pid) {
        map.set(_pid, new ProcessNode(_pid, []))
    }
    for (let [idx, _ppid] of ppid.entries()) {
        let fatherNode = map.get(_ppid);
        let curNode = map.get(pid[idx]) as ProcessNode;
        fatherNode?.childs?.push(curNode);
    }
    let killNode = map.get(kill);
    let res = [] as Array<number>;
    const dfs = (node: ProcessNode) => {
        if (node == null) return;
        for (let child of node.childs) {
            dfs(child);
        }
        res.push(node.val);
    }
    dfs(killNode);
    return res
};