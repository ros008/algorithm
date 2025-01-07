function solution(n, computers) {
  let answer = 0;

  const visited = new Array(n).fill(false);

  for (let i = 0; i < n; i++) {
    if (visited[i]) continue;
    answer += 1;
    const queue = [i];
    visited[i] = true;
    let pivot = 0;

    while (pivot < queue.length) {
      const cur = queue[pivot++];
      for (let j = 0; j < n; j++) {
        if (computers[cur][j] === 1 && !visited[j]) {
          queue.push(j);
          visited[j] = true;
        }
      }
    }
  }

  return answer;
}
