import sys

input = sys.stdin.readline

a, s, k, x, y = map(int, input().split())

z = (s-a+k*y)/(x+y)

if z >= 0 and z % 1 == 0:
    print(int(z))
else:
    print(-1)