fin = open("names.in", "r")
fout = open("names.out", "w")

n = int(fin.readline())
adj = [fin.readline().split() for i in range(n)]
for i in range(n):
    flag = False
    st = adj[i][0]
    for j in range(n):
        if j == i:
            continue
        if (st == adj[j][0]) or (st == adj[j][1]):
            flag = True
            break
    if flag:
        exchanger = adj[i][2]
        adj[i][2] = adj[i][1]
        adj[i][1] = adj[i][0]
        adj[i][0] = exchanger        
adj.sort()
for i in range(n):
    print(*adj[i], file = fout)

fin.close()
fout.close()