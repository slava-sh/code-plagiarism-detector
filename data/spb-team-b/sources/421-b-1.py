

fin = open("chess.in", 'r')
fout = open("chess.out", 'w')

n = int(fin.readline().strip())
a = list(map(int, fin.readline().strip().split(' ')))
a.append(-1)

i = 1;
while (i <= a[i - 1]):
    i += 1;
i -= 1;

fout.write(str(i) + '\n')
for j in range(i):
    fout.write(str(j + 1) + ' ' + str(j + 1) + '\n')

fin.close()
fout.close()