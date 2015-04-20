fin = open("dunes.in", "r")
fout = open("dunes.out", "w")

n, m = map(int, fin.readline().split())
a = []
for i in range(n):
    a.append(list(map(int, fin.readline().split())))
for i in range(m):
    q = int(fin.readline())
    cnt = 0
    for j in range(n):
        if a[j][0] <= q <= a[j][1]:
            cnt += a[j][2] if (q - a[j][0]) % 2 == 0 else -a[j][2]
    print(cnt, file=fout)

fin.close()
fout.close()