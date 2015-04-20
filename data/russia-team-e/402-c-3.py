def readdata():
    global n, graph, u0, v0
    fread = open('dwarfs.in', 'r')
    n = int(fread.readline())
    graph = [[] for i in range(n)]
    for i in range(n - 1):
        x, y = [int(x) for x in fread.readline().split()]
        graph[x - 1].append(y - 1)
        graph[y - 1].append(x - 1)
    u0, v0 = [int(x) for x in fread.readline().split()]
    u0 -= 1
    v0 -= 1
    
    
def dfs1(v):
    used[v] = True
    for x in graph[v]:
        if not used[x]:
            dfs1(x)
            pred[x] = v
    
    
def find_path():
    global used, path, k, pred
    used = [False] * n
    pred = [0] * n
    dfs1(u0)
    cur = v0
    path = []
    while cur != u0:
        path.append(cur)
        cur = pred[cur]
    path.append(u0)
    k = len(path)
    
    
def dfs2(v, l):
    global maxx
    maxx = max(maxx, l)
    used[v] = True
    for to in graph[v]:
        if not used[to]:
            dfs2(to, l + 1)
    
    
def count_dicks():
    global used, maxx, dick
    dick = [0] * k
    used = [False] * n
    for x in path:
        used[x] = True
    for i in range(k):
        maxx = 0
        dfs2(path[i], 0)
        dick[i] = maxx
        
        
def count_f_and_g():
    global f, g
    f = [0] * (k - 1)
    g = [0] * (k - 1)
    f[0] = dick[0]
    for i in range(1, k - 1):
        f[i] = max(f[i - 1], dick[i] + i)
    g[k - 2] = dick[k - 1]
    for i in range(k - 3, -1, -1):
        g[i] = max(g[i + 1], dick[i + 1] + k - i)
    #print(path)
    #print(dick)
    #print(f, g)
        
        
def write_answer():
    ans = 0
    for i in range(k - 1):
        if min(f[i], g[i]) > ans:
            ans = min(f[i], g[i])
    fwrite = open('dwarfs.out', 'w')
    print(ans + 1, file = fwrite)
    fwrite.close()


readdata()
find_path()
count_dicks()
count_f_and_g()
write_answer()