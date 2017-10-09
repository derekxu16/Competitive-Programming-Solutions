from heapq import *
import sys
input = sys.stdin.readline

for zzz in range(int(input())):
    n, m = [int(x) for x in input().split()]

    edges = [[-1 for x in range(n+1)] for x in range(n+1)]

    graph = [set() for x in range(n+1)]

    for x in range(m):
        a, b, e = [int(x) for x in input().split()]
        if b != a:
            if e < edges[a][b] or edges[a][b] == -1:
                edges[a][b] = e
                edges[b][a] = e
                graph[a].add(b)
                graph[b].add(a)

    start = int(input())
    
    d = [9999999 for x in range(n+1)]
    queue = []

    d[start] = 0

    heappush(queue, (d[start], start))

    visited = set()

    while queue:
        node = heappop(queue)[1]
        cost = d[node]
        if node not in visited:
            visited.add(node)
            for adj in graph[node]:
                if edges[node][adj] + cost < d[adj]:
                    d[adj] = edges[node][adj] + cost
                    heappush(queue,(d[adj],adj))
                    
    for x in range(1,n+1):
        if x != start:
            if d[x] == 9999999:
                print(-1, end = " ")
            else:
                print(d[x], end = " ")
    print("")
