const fs = require("fs");
const stdin = fs.readFileSync(0, "utf-8").trim().split("\n");
const input = (() => {
  let line = 0;
  return () => stdin[line++].split(" ").map(Number);
})();

const [n, m] = input();
const route = Array.from({ length: n + 1 }).map(() => new Array());
const routeR = Array.from({ length: n + 1 }).map(() => new Array());

for (let i = 0; i < m; i++) {
  const [from, to] = input();
  route[from].push(to);
  routeR[to].push(from);
}

const [S, T] = input();

function bfs(start, adj, visited) {
  const queue = [start];
  visited[start] = true;
  let pivot = 0;
  while (pivot < queue.length) {
    const cur = queue[pivot++];
    for (let i = 0; i < adj[cur].length; i++) {
      const next = adj[cur][i];
      if (!visited[next]) {
        queue.push(next);
        visited[next] = true;
      }
    }
  }
}

const fromS = new Array(n + 1).fill(false);
fromS[T] = true;
bfs(S, route, fromS);

const fromT = new Array(n + 1).fill(false);
fromT[S] = true;
bfs(T, route, fromT);

const toS = new Array(n + 1).fill(false);
bfs(S, routeR, toS);

const toT = new Array(n + 1).fill(false);
bfs(T, routeR, toT);

let answer = 0;
for (let i = 1; i <= n; i++) {
  if (i !== S && i !== T && fromS[i] && fromT[i] && toS[i] && toT[i])
    answer += 1;
}
console.log(answer);
