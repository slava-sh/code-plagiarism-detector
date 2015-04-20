fin = open("dunes.in", 'r')
fout = open("dunes.out", 'w')

n, m = list(map(int, fin.readline().strip().split(' ')))
g = [0] * m
l = [0] * n
r = [0] * n
x = [0] * n

for i in range(n):
    l[i], r[i], x[i] = list(map(int, fin.readline().strip().split(' ')))
for i in range(m):
    g[i] = int(fin.readline().strip())
a = [0] * g[m - 1]
for i in range(n):
    for j in range(l[i] - 1, r[i], 2):
        a[j] += x[i]
    for j in range(l[i], r[i], 2):
        a[j] -= x[i]
for i in range(m):
    fout.write(str(a[g[i] - 1]) + '\n')
    
fin.close()
fout.close()
