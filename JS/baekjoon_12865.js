const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";

const stdin = fs.readFileSync(filePath).toString().trim().split("\n");
const input = (() => {
    let line = 0;
    return () => stdin[line++].split(' ').map(Number);
})();

const [N, K] = input();

// const dp = new Array(N + 1).fill(0).map(() => new Array(K + 1).fill(0));

// for(let i=1; i<N + 1; i++) {
//     const [W, V] = input();
//     for(let j=1; j<K + 1; j++) {
//         if(j >= W) dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - W] + V);
//         else dp[i][j] = dp[i - 1][j];
//     }
// }
// console.log(dp[N][K]);

const dp2 = new Array(K + 1).fill(0);
for(let i=0; i<N; i++) {
    const [W, V] = input();
    for(let j=K; j>=W; j--) {
        if(dp2[j - W] + V >= dp2[j]) dp2[j] = dp2[j - W] + V;
    }
}
console.log(dp2[K])