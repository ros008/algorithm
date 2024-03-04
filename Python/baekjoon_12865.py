from sys import stdin as s

s = open("../input.txt", "rt");

N, K = map(int, s.readline().strip().split())

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1, N + 1):
    W, V = map(int, s.readline().strip().split())
    for j in range(1, K + 1):
        if j >= W:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V)
        else:
            dp[i][j] = dp[i - 1][j]
            
print(dp[N][K])
