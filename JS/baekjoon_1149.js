const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [inputN, ...input] = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(inputN);

const cost = input.map((nums) => nums.split(" ").map(n => parseInt(n)))

for(let i=1; i<n; i++) {
    cost[i][0] = Math.min(cost[i-1][1]+cost[i][0], cost[i-1][2]+cost[i][0]);
    cost[i][1] = Math.min(cost[i-1][0]+cost[i][1], cost[i-1][2]+cost[i][1]);
    cost[i][2] = Math.min(cost[i-1][0]+cost[i][2], cost[i-1][1]+cost[i][2]);
}

console.log(Math.min(...cost[n-1]));

