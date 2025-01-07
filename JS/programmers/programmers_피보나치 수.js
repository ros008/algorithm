function solution(n) {
    const DIVISOR = 1234567;
    let answer = 0;
    let fib0 = 0;
    let fib1 = 1;
    
    for(let i=2; i<=n; i++) {
        answer = (fib0 + fib1) % DIVISOR;
        fib0 = fib1;
        fib1 = answer;
    }
    
    return answer;
}