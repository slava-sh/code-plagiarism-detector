fin = open('chess.in')
fout = open('chess.out', 'w')
n = int(fin.readline())
cut = 0
a = [int(i) for i in fin.readline().split()]
for i in range(n):
    if a[i] < i + 1:
        break
    cut += 1
print(cut, file = fout)
for i in range(cut):
    print(i + 1, i + 1, file = fout)
fin.close()
fout.close()