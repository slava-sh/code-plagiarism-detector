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
height = [0 for i in range(min(l), max(r) + 1)]
for i in range(n):
    for j in range(l[i], r[i]):
        if (l[i] - j) % 2 == 0:
            height[j - min(l)] += x[i]
        else:
            height[j - min(l)] -= x[i]
for i in q:
    if i < min(l):
        print(0, file = fout)
    elif i - 1 - min(l) >= len(height):
        print(0, file = fout)
    else:
        print(height[i - 1- min(l)], file = fout)
fin.close()
fout.close()