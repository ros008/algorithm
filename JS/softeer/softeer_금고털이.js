const fs = require("fs");
const stdin = fs.readFileSync(0, "utf-8").trim().split("\n");
const input = (() => {
  let line = 0;
  return () => stdin[line++].split(" ").map(Number);
})();

let [W, N] = input();
const jewelry = [];
for (let i = 0; i < N; i++) {
  const jew = input();
  jewelry.push(jew);
}

jewelry.sort((a, b) => b[1] - a[1]);
let answer = 0;
for (let i = 0; i < jewelry.length; i++) {
  const [M, P] = jewelry[i];
  if (W > M) {
    answer += M * P;
    W -= M;
  } else {
    answer += W * P;
    break;
  }
}
console.log(answer);
