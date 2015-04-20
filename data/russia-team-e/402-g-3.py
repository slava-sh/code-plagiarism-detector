def ans(n, m):
    if n == 1 or m == 1:
        return (max(n, m) + 1) // 4
    if n < 3 or m < 3:
        return 0
    return 1


fread = open('prizes.in', 'r')
fwrite = open('prizes.out', 'w')
n, m = [int(x) for x in fread.readline().split()]
print(ans(n, m), file = fwrite)
fwrite.close()