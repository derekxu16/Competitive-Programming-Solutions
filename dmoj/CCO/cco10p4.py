types = int(input())

parts = {}
memo = {}

numprts = int(input())

for x in range(numprts):
    a,b,c = [int(x) for x in input().split()]
    if c not in parts.keys():
        parts[c] = []
    parts[c].append((a,b))

budget = int(input())

def dp(i,budget):
    if (i,budget) in memo.keys():
        return memo[(i,budget)]
    if budget < 0:
        return - 999999999
    if i == types + 1:
        return 0
    maximum = 0
    for part in parts[i]:
        current = dp(i+1,budget - part[0]) + part[1]
        if current > maximum:
            maximum = current
    if dp(i+1,budget) > maximum:
        maximum = dp(i+1,budget)
    memo[(i,budget)] = maximum
    return maximum

print(dp(1,budget))
