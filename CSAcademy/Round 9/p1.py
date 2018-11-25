import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

count = [0 for i in range(3)]
for num in a:
    count[num%3] += 1

print(count[0]*(count[0]-1)//2 + count[1] * count[2])