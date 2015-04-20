fin = open('chess.in')
fout = open('chess.out', 'w')
n = int(fin.readline())
cut = 0
a = [int(i) for i in fin.readline().split()]
i = 0
while (a[i] >= i):
    cut += 1
    i += 1
print(cut, file = fout)
for i in range(cut):
    print(i + 1, i + 1, file = fout)
fin.close()
fout.close()