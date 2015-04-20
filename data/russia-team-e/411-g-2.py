fin = open('prizes.in', 'r')
fout = open('prizes.out', 'w')

n, m = [int(i) for i in input().split()]
print(min(n // 3, m // 3), file = fout)

fin.close()
fout.close()