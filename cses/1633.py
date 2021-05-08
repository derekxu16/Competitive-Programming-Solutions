MOD = int(1e9 + 7)

n = int(input())

dp = [0 for i in range(n + 1)]
dp[0] = 1

for i in range(n):
    for j in range(1, 7):
        if i + j > n:
            continue
        dp[i + j] += dp[i]
        dp[i + j] %= MOD

print(dp[n])
