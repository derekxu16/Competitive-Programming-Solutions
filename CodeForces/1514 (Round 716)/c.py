from math import gcd
import sys

input = sys.stdin.readline

n = int(input())

ans = []
prod = 1
for i in range(n):
    if gcd(n, i) == 1:
        prod *= i
        prod %= n
        ans.append(i)

if prod != 1:
    ans.pop()

print(len(ans))
print(' '.join(map(str, ans)))
