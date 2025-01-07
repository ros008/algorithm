const fs = require("fs");
const stdin = fs.readFileSync(0, "utf-8").trim().split("\n");
const input = (() => {
  let line = 0;
  return () => stdin[line++].split(" ").map(Number);
})();

const [N, K] = input();
const scoreArr = input();

for (let i = 0; i < K; i++) {
  const [start, end] = input();
  // const avg = ((scoreArr.slice(start - 1, end).reduce((acc, cur) => acc + cur, 0)) / (end - start + 1)).toFixed(2);
  let answer = 0;
  for (let j = start - 1; j < end; j++) {
    answer += scoreArr[j];
  }
  answer /= end - start + 1;
  console.log(answer.toFixed(2));
}

// TID
// slice는 새로운 배열을 생성하기 때문에 시간 복잡도 O(N), 공간 복잡도 O(N)가 올라간다. 이 문제의 경우 2초라는 시간 복잡도의 제약이 존재했고, 이로인해 slice를 사용하면 시간초과가 났다.
// 따라서 for문을 사용해 새로운 배열을 생성하는 대신 기존의 배열을 순회만 해서 합을 구한다.
