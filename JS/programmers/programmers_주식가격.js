function solution(prices) {
    const answer = new Array(prices.length).fill(0);
    const n = prices.length;
    const stack = [];
    
    for(let i=0; i<n; i++) {
        while (stack.length > 0 && prices[i] < prices[stack[stack.length - 1]]) {
            const top = stack.pop();
            answer[top] = i - top; 
        }
        stack.push(i);
    }
    
    while(stack.length > 0) {
        const top = stack.pop();
        answer[top] = n - 1 - top;
    }
        
    return answer;
}