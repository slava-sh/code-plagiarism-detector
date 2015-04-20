f = open("dunes.in", "r")

n, m = [int(i) for i in f.readline().split()]

l = [0] * n
r = [0] * n
x = [0] * n

for i in range(n):
    l[i], r[i], x[i] = [int(i2) for i2 in f.readline().split()]

dunes   = [0] * m
dunes_h = [0] * m

for i in range(m):
    dunes[i] = int(f.readline())

for i in range(m):
    for i2 in range(n):
        if l[i2] <= dunes[i] <= r[i2]:
            dunes_h[i] = dunes_h[i] + x[i2] * (-1) * ((dunes[i] - l[i2]) % 2 * 2 - 1)

f = open("dunes.out", "w")

for i in range(m):
    f.write(str(dunes_h[i]) + "\n")




