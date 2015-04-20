fread = open('prizes.in', 'r')
fwrite = open('prizes.out', 'w')
n, m = [int(x) for x in fread.readline().split()]
if n > 1 and m > 1:
    print((min(n, m) + 1) // 4, file = fwrite)
else:
    print((max(n, m) + 1) // 4, file = fwrite)
fwrite.close()