fin = open('dunes.in')
fout = open('dunes.out', 'w')
n, m = map(int, fin.readline().split())
l = []
r = []
x = []
q = []
for i in range(n):
    li, ri, xi = map(int, fin.readline().split())
    l.append(li - 1)
    r.append(ri)
    x.append(xi)
for i in range(m):
    j = int(fin.readline())
    q.append(j)
height = [0 for i in range(max(r) + 1)]
for i in range(n):
    for j in range(l[i], r[i]):
        if (l[i] - j) % 2 == 0:
            height[j] += x[i]
        else:
            height[j] -= x[i]
for i in q:
    if i - 1 > len(height):
        print(0, file = fout)
    print(height[i - 1], file = fout)
fin.close()
fout.close()