import sys
sys.setrecursionlimit(30000)
sys.stdin = open('binary.in')
sys.stdout = open('binary.out', 'w')

def fail():
    print(0)
    sys.exit()

n = int(input())
z = list(map(int, input().split()))
graph = [[0] * n for i in range(n)]
if z[0] not in (-1, 0):
    fail()
z[0] = n
for i in range(1, n):
    if z[i] == -1:
        continue
    try:
        for j in range(z[i]):
            graph[j][i+j] = 1
            graph[i+j][j] = 1
    except:
        fail()
    if i + z[i] < n:
        graph[z[i]][i+z[i]] = 2
        graph[i+z[i]][z[i]] = 2

color = [0] * n


visited = set()

def dfs(v):
    if v in visited:
        return
    visited.add(v)
    for v2 in range(n):
        if graph[v][v2]:
            newcolor = color[v] if graph[v][v2] == 1 else (3 - color[v])
            if color[v2] and color[v2] != newcolor:
                fail()
            color[v2] = newcolor
            dfs(v2)
   
cmp = 0         
for i in range(n):
    if i not in visited:
        cmp += 1
        color[i] = 1
        dfs(i)
        
print(pow(2, cmp, 10**9 + 7))