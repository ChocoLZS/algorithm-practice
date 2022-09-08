/**
 Do not return anything, modify board in-place instead.
 */
function solve(board: string[][]): void {
    for (let i = 0; i < board.length; i++) {
        if (board[i][0] == 'O') {
            spread(board, i, 0);
        }
        if (board[i][board[0].length - 1] == 'O') {
            spread(board, i, board[0].length - 1);
        }
    }
    for (let j = 0; j < board[0].length; j++) {
        if (board[0][j] == 'O') {
            spread(board, 0, j);
        }
        if (board[board.length - 1][j] == 'O') {
            spread(board, board.length - 1, j);
        }
    }
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == 'A') {
                board[i][j] = 'O'
            }
        }
    }
};

function spread(board: string[][], x: number, y: number) {
    if (x < 0 || y < 0 || x > board.length - 1 || y > board[0].length - 1) {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] == 'B';
        spread(board, x - 1, y);
        spread(board, x + 1, y)
        spread(board, x, y - 1);
        spread(board, x, y + 1);
    }
}
