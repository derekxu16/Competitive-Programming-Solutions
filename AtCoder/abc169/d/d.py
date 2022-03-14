from math import floor, sqrt
import sys

input = sys.stdin.readline

n = int(input())

ans = 0
x = 2
while x*x <= n:
    count = 0
    while n % x == 0:
        count += 1
        n //= x
    ans += floor((-1 + sqrt(1 + 8*count)) / 2)
    x += 1

if n > 1:
    ans += 1

print(ans)
