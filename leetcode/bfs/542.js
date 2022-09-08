/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
const biases = [[0, -1], [0, 1], [-1, 0], [1, 0]]
var updateMatrix = function (mat) {
    let visited = Array.from(new Array(mat.length), () => new Array(mat[0].length).fill(false));
    let dist = Array.from(new Array(mat.length), () => new Array(mat[0].length).fill(Infinity));
    let queue = []
    for (let i = 0; i < mat.length; i++) {
        for (let j = 0; j < mat[0].length; j++) {
            if (mat[i][j] == 0) {
                visited[i][j] = true;
                queue.push([i.j]);
            }
        }
    }
    let step = 0;
    while (queue.length) {
        let size = queue.length;
        for (let i = 0; i < size; i++) {
            let [x, y] = queue.pop();
            if (mat[x][y] == 1) {
                dist[x][y] = step;
            }
            for (let [dx, dy] of biases) {
                if (x + dx < 0 || y + dy < 0 || x + dx >= mat.length || y + dy >= mat[0].length
                    || visited[x + dx][y + dy]
                ) continue;
                queue.add([x + dx, y + dy]);
                visited[x + dx, y + dy] = true;
            }
        }
        step++;
    }
    return dist;
};




