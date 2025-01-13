/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
  let rows = Array.from({ length: 9 }, () => new Set());
  let cols = Array.from({ length: 9 }, () => new Set());
  let boxes = Array.from({ length: 9 }, () => new Set());

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (board[i][j] === ".") continue;

      let value = board[i][j];
      let boxIdx = Math.floor(i / 3) * 3 + Math.floor(j / 3);

      if (rows[i].has(value) || cols[j].has(value) || boxes[boxIdx].has(value))
        return false;

      rows[i].add(value);
      cols[j].add(value);
      boxes[boxIdx].add(value);
    }
  }

  return true;
};
