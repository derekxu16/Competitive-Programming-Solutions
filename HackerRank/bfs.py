q = int(input())

for zzz in range(q):
    n, m = map(int, input().split())
    graph = [[] for x in range(n+1)]

    for z in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    start = int(input())

    q = [[start]]
    visited = set()
    d = {}

    while q:
        path = q.pop(0)
        node = path[-1]
        if node not in visited:
            visited.add(node)
            d[node] = len(path) - 1
            for adj in graph[node]:
                if adj not in visited:
                    newpath = list(path)
                    newpath = newpath + [adj]
                    q.append(newpath)
    
    for x in range(1,n+1):
        if x == start:
            continue
        ans = d.get(x,-1)
        if ans == -1:
            print(-1, end=" ")
        else: print(ans*6, end = " ")
    print("")