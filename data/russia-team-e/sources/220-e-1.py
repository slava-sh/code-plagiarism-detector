fin = open('sochi.in')
fout = open('sochi.out', 'w')
n, d = map(int, fin.readline().split())
a = list(map(int, fin.readline().split()))
a.sort()
if n == 1:
    print(a[0])#, file = fout)
elif a[n - 1] <= d:
    print(a[n - 1])#, file = fout)
else:
    cur = 0
    while cur < n - 1 and a[cur] <= d:
        cur += 1
    if cur == n - 1:
        print(a[n - 1])#, file = fout)
    else:
        length = a[cur] + a[cur + 1] - 2 * d
        for i in range(cur + 2, n):
            if a[i] - 2 * d >= d:
                length += a[i] - 2 * d
        print(length)#, file = fout)