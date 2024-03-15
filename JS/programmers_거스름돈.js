function solution(n, money) {
    const DIVISOR = 1000000007;
    
    const dp = new Array(n + 1).fill(0);
    
    dp[0] = 1;
    
    for(let i=0; i<money.length; i++) {
        const mon = money[i];
        for(let j=mon; j<=n; j++) {
            dp[j] = (dp[j] + dp[j - mon]) % DIVISOR;    
        }
    }
    
    return dp[n];
}

// 1 0 0 0 0 0 : 초기값
// 1 1 1 1 1 1 : 1 사용 dp[i] = dp[i] + dp[i - 1]
// 1 1 2 2 3 3 : 1,2 사용 dp[i] = dp[i] + dp[i - 2] 이때, 예를 들어 dp[3]를 계산한다 칠 때, 기존 dp[3] (1로만 3을 만들 수 있는 경우의 수 = 1) + dp[3 - 2] 기존 1로만 1을 만들 수 있는 경우의 수 = 1(2 더하면 3 되니까..) 
// 1 1 2 2 3 4 : 1,2,5 사용 dp[i] = dp[i] + dp[i - 5]