def solution(prices):
    answer = [0 for _ in range(len(prices))]
    stack = [];
    
    for i, price in enumerate(prices):
        while len(stack) > 0 and price < prices[stack[-1]]:
            top = stack.pop();
            answer[top] = i - top;
        stack.append(i)
        
    while len(stack) > 0:
        top = stack.pop();
        answer[top] = i - top;
        
    return answer