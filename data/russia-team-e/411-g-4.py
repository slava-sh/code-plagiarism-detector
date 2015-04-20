fin = open('prizes.in', 'r')
fout = open('prizes.out', 'w')

n, m = [int(i) for i in fin.readline().split()]
if n == 1 or m == 1:
    print(max(n // 3, m // 3), file = fout())
else:
    print((n // 3, m // 3), file = fout)

fin.close()
fout.close()