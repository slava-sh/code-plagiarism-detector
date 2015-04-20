ftr = open("prizes.in", "r")
ftw = open("prizes.out", "w")

n, m = map(int, ftr.readline().split())
print((min(n, m) + 2) // 4, file = ftw)
ftw.close()