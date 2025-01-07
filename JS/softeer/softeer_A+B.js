const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [T, ...input] = fs.readFileSync(filePath).toString().trim().split("\n");

for (let tc = 0; tc < T; tc++) {
  const [a, b] = input[tc]
    .trim()
    .split(" ")
    .map((v) => Number(v));
  console.log(`Case #${tc + 1}:`, a + b);
}
