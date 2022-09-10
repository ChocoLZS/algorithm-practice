const bias = [
    [-1, 0], [1, 0],
    [0, -1], [0, 1]
]


/**
 * @param {number[][]} rooms
 * @return {void} Do not return anything, modify rooms in-place instead.
 */
var wallsAndGates = function (rooms) {
    let gates = new Set();
    let m = rooms.length;
    let n = rooms[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                gates.add([i, j]);
            }
        }
    }
    for (let [x, y] of gates) {
        let visited = Array.from(new Array(m), () => new Array(n).fill(false));
        let queue = [];
        let dis = 0;
        queue.push([x, y]);
        while (queue.length != 0) {
            let queLen = queue.length;
            for (let i = 0; i < queLen; i++) {
                let [curX, curY] = queue.shift();
                if (visited[curX][curY]) continue;
                visited[curX][curY] = true;
                switch (rooms[curX][curY]) {
                    case -1:
                        continue;
                    case 0:
                        break;
                    default:
                        rooms[curX][curY] = Math.min(rooms[curX][curY], dis);
                        break;
                }
                for (let [dx, dy] of bias) {
                    if (curX + dx < 0 || curY + dy < 0 || curX + dx >= m || curY + dy >= n) continue;
                    if (visited[curX + dx][curY + dy]) continue;
                    queue.push([curX + dx, curY + dy]);
                }
            }
            dis++;
        }
    }
};