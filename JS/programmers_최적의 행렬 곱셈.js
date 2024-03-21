function solution(matrix_sizes) {
  var answer = 0;
  const N = matrix_sizes.length;

  // dp[i][j] i 부터 j번째 행렬까지 최소 연산 횟수
  // dp[i][j] = Math.min(dp[i][j], dp[i][k] * dp[k+1][j] + (matrix_sizes[i][0] * matrix_sizes[k+1][0] * matrix_sizes[j[1]]));

  const dp = Array.from({ length: N + 1 }, () => new Array(N + 1).fill(0));

  for (let gap = 1; gap < N; gap++) {
    for (let start = 0; start < N - gap; start++) {
      const end = start + gap;
      const list = [];
      for (let k = start; k < end; k++) {
        list.push(
          dp[start][k] +
            dp[k + 1][end] +
            matrix_sizes[start][0] *
              matrix_sizes[k + 1][0] *
              matrix_sizes[end][1]
        );
      }
      // console.log(list, start, end)
      dp[start][end] = Math.min(...list);
    }
  }

  // console.log(dp)
  // console.log(dp[0][N-1])

  return dp[0][N - 1];
}
