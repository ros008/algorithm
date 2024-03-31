const fs = require("fs");
const stdin = fs.readFileSync(0, "utf-8").trim().split("\n");
const input = (() => {
  let line = 0;
  return () => stdin[line++].split(" ").map(Number);
})();

const [N] = input();
const height = input();

const dp = new Array(N).fill(1);

for (let i = 1; i < N; i++) {
  for (let j = 0; j < i; j++) {
    if (height[i] > height[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}
console.log(Math.max(...dp));
