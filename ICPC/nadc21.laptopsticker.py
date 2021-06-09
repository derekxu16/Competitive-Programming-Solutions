import sys
input = sys.stdin.readline

wc, hc, ws, hs = map(int, input().split())

print(1 if ((wc - ws) >= 2 and (hc - hs) >= 2) else 0)
