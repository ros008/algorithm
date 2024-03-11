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