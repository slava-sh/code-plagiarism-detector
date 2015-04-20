ftr = open("prizes.in", "r")
ftw = open("prizes.out", "w")

n, m = map(int, ftr.readline().split())
if min(n, m) != 1:
    print((min(n, m) + 1) // 4, file = ftw)
else:
    print((max(n, m) + 1) // 4, file = ftw)
ftw.close()