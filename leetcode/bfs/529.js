/**
 * @param {character[][]} board
 * @param {number[]} click
 * @return {character[][]}
 */

const biases = [
    [-1, -1], [-1, 0], [-1, 1],
    [0, -1], [0, 1],
    [1, -1], [1, 0], [1, 1]];

var updateBoard = function (board, click) {
    let [row, col] = click;
    switch (board[row][col]) {
        case 'M':
            board[row][col] = 'X';
            break;
        case 'E':
            flipGrid(board, row, col);
            break;
        case 'B':
            break;
        case 'X':
            break;
        default:
            break;
    }
    return board;
};

function flipGrid(board, row, col) {
    if (row < 0 || col < 0 || row >= board.length || col >= board[0].length) return;
    switch (board[row][col]) {
        case 'E':
            let count = 0;
            for (let [x, y] of biases) {
                if (row + x < 0 || col + y < 0 || row + x >= board.length || col + y >= board[0].length) {
                    continue
                } else {
                    if (board[row + x][col + y] == 'M' || board[row + x][col + y] == 'X') {
                        count++;
                    }
                }

            }
            if (count == 0) {
                board[row][col] = 'B';
                for (let [x, y] of biases) {
                    flipGrid(board, row + x, col + y);
                }
            } else {
                board[row][col] = count.toString();
            }
            break;
        default:
            break;
    }
}

updateBoard([["E", "E", "E", "E", "E"], ["E", "E", "M", "E", "E"], ["E", "E", "E", "E", "E"], ["E", "E", "E", "E", "E"]],
    [3, 0])