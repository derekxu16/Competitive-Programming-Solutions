from heapq import *
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for x in range(m):
    a, b, e = map(int, input().split())
    if b != a:
        graph[a].append((b, e))
        graph[b].append((a, e))

inf = 99999999
d = [inf for _ in range(n + 1)]
d[1] = 0
q = []
heappush(q, (d[1], 1))

while len(q):
    d_u, u = heappop(q)
    for v, e in graph[u]:
        if d_u + e < d[v]:
            d[v] = d_u + e
            heappush(q, (d[v], v))
    
for u in range(1, n + 1):
    if d[u] == inf:
        print(-1)
    else:
        print(d[u])
