const dx = [1, 0, -1, 0];
const dy = [0, -1, 0, 1];

function bfs(map, n, m) {
  const max = n * m + 1;
  let minWay = max;
  const queue = [[0, 0, 1]]; // 시작 점 x, y, 거리
  const [destX, destY] = [n - 1, m - 1];
  const visited = Array.from({ length: n }).map(() => new Array(m).fill(false));
  visited[0][0] = true;
  let pivot = 0;
  while (pivot < queue.length) {
    const [curX, curY, curDist] = queue[pivot++];
    if (curX === destX && curY === destY) {
      minWay = Math.min(minWay, curDist);
      continue;
    }
    for (let i = 0; i < 4; i++) {
      const [nextX, nextY] = [curX + dx[i], curY + dy[i]];
      if (
        nextX >= 0 &&
        nextX < n &&
        nextY >= 0 &&
        nextY < m &&
        map[nextX][nextY] === 1 &&
        !visited[nextX][nextY]
      ) {
        queue.push([nextX, nextY, curDist + 1]);
        visited[nextX][nextY] = true;
      }
    }
  }
  return minWay === max ? -1 : minWay;
}

function solution(maps) {
  let answer = 0;
  const n = maps.length;
  const m = maps[0].length;

  answer = bfs(maps, n, m);

  return answer;
}
