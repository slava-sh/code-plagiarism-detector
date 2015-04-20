import sys
sys.setrecursionlimit(10000000)
sys.stdin = open('dwarfs.in')
sys.stdout = open('dwarfs.out', 'w')

try:
    n = int(input())
    neigs = [[] for i in range(n)]
    for i in range(n - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        neigs[a].append(b)
        neigs[b].append(a)
    
    g1, g2 = map(int, input().split())
    g1 -= 1
    g2 -= 1
    
    visited1 = set()
    p = []
    def dfs1(v):
        if v in visited1:
            return False
        visited1.add(v)
        p.append(v)
        if v == g2:
            return True
        for v2 in neigs[v]:
            if dfs1(v2):
                return True
        p.pop()
        return False
    
    dfs1(g1)
    visited = set(p)
    p2 = set(p)
    
    def dfs(v):
        visited.add(v)
        return max([0] + [dfs(v2) for v2 in neigs[v] if v2 not in visited]) + 1
    
    
    res = [dfs(v) for v in p]
    
    maxs = [None] * len(res) # maxs[i] = max(res[i:])
    maxs[-1] = res[-1]
    for i in reversed(range(len(res) - 1)):
        maxs[i] = max(maxs[i+1], res[i] + len(res)-i-1)
    total = 0
    for i in range(len(res) - 1):
        total = max(total, min(res[i]+i, maxs[i+1]))
        
    print(total)
except:
    print(1)