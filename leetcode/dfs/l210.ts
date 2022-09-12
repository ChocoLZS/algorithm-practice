// DFS
// function findOrder(numCourses: number, prerequisites: number[][]): number[] {
//     let edges = Array.from(new Array(numCourses), () => new Array());
//     let visited = new Array(numCourses).fill(0);
//     let stack = new Array(numCourses);
//     let valid = true;
//     let index = numCourses - 1;
//     for (let [next, pre] of prerequisites) {
//         edges[pre].push(next);
//     }
//     const dfs = (u) => {
//         visited[u] = 1;
//         for (let v of edges[u]) {
//             if (visited[v] == 0) {
//                 dfs(v);
//                 if (!valid) {
//                     return;
//                 }
//             } else if (visited[v] == 1) {
//                 valid = false;
//                 return;
//             }
//         }
//         visited[u] = 2;
//         stack[index--] = u;
//     }
//     for (let i = 0; i < numCourses && valid; i++) {
//         if (visited[i] == 0) {
//             dfs(i);
//         }
//     }
//     if (!valid) {
//         return [];
//     }
//     return stack;
// };

//bfs
function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    let edges = Array.from(new Array(numCourses), () => new Array());
    let inDegree = new Array(numCourses);
    let result = [] as Array<number>;
    for (let [next, pre] of prerequisites) {
        edges[pre].push(next);
        inDegree[next]++;
    }
    let queue = new Array();
    for (let i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue.push(i);
        }
    }
    while (queue.length !== 0) {
        let u = queue.shift() as number;
        result.push(u);
        for (let v of edges[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue.push(v);
            }
        }
    }
    if (result.length !== numCourses) return [];
    return result;
}