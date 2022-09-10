/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function (isConnected) {
    let visited = new Array(isConnected.length).fill(false);
    let rest = new Set();
    for (let i = 0; i < isConnected.length; i++) {
        rest.add(i);
    }
    let queue = [];
    let res = 0;

    while (rest.length > 0) {
        let start = Array.from(rest)[0];
        rest.delete(start);
        for (let index of rest) {
            if (!visited[index] && isConnected[start][index] == 1) queue.push(index);
        }
        while (queue.length) {
            let peer = queue.shift();
            visited[peer] = true;
            rest.delete(peer);
            for (let index of rest) {
                if (!visited[index] && isConnected[peer][index] == 1) queue.push(index);
            }
        }
        res++;
    }
    return res;
};