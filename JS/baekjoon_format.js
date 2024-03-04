//////// 입력 값 받기 //////////
const fs = require('fs');
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

// 1. 입력값이 한 개일 때 (한 줄)
/* ex) 1 */
const input = fs.readFileSync(filePath).toString().trim();

// 2. 입력값이 여러 개일 때 (한 줄에 공백으로 구분)
/* ex) 1 2 */ 
const input = fs.readFileSync(filePath).toString().trim().split(" ");

// 3. 입력값이 여러 줄일 때
/* ex) 
1 
2
3 
*/
const input = fs.readFileSync(filePath).toString().trim().split("\n");


// 4. 입력값이 첫 번째 줄에는 입력 값의 길이(n), 두 번째 줄에 공백으로 구분된 입력 값이 주어질 때
/* ex) 
3
10 20 30  
*/
const [n, input] = fs.readFileSync(filePath).toString().trim().split("\n");
const inputArr = input.trim().split(" ");


// 5. 입력값이 첫 번째 줄에는 입력 값의 길이(n), n개의 줄에 걸쳐서 한 줄에 하나의 입력 값이 주어질 때
/* ex) 
3
10
20
30
*/
const [n, input] = fs.readFileSync(filePath).toString().trim().split("\n");

// 6. 입력값이 첫 번째 줄에는 입력 값의 길이(n), n개의 줄에 걸쳐서 한 줄에 여러개의 입력 값이 주어질 때
/* ex) 
3
10 20 30
20 30 40
30 40 50
*/
const [n, ...input] = fs.readFileSync(filePath).toString().trim().split("\n");

for(let i=1; i<input.length; i++) {
    cost.push(input[i].trim().split(" "));
}

////////// 이중 배열 생성하기 //////////
const arr = new Array(n).fill(0).map(() => new Array(3));
