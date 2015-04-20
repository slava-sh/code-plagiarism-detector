fin = open('prizes.in', 'r')
fout = open('prizes.out', 'w')

n, m = [int(i) for i in fin.readline().split()]
if n == 1 or m == 1:
    print(max((n + 1) // 4, (m + 1) // 4), file = fout)
elif n == 2 or m == 2:
    print(0, file = fout)
else:
    print(1, file = fout)
fin.close()
fout.close()