function solution(n, times) {
  let answer = 0;

  times.sort((a, b) => a - b);

  let start = 1;
  let end = times[times.length - 1] * n;
  let mid = Math.floor((start + end) / 2);

  while (start <= end) {
    const pass = times.reduce((sum, cur) => sum + Math.floor(mid / cur), 0);
    if (pass >= n) end = mid - 1;
    else start = mid + 1;
    mid = Math.floor((start + end) / 2);
  }
  // console.log(start, end);

  return start;
}
