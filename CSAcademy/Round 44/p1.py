import sys

input = sys.stdin.readline

n, k = map(int,input().split())

count = [0 for i in range(1001)]

for i in map(int,input().split()):
    count[i] += 1

ans = 0

for i in range(1001):
    if count[i] >= k:
        ans += 1
    
print(ans)