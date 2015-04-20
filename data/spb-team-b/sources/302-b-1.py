fin = open("chess.in", "r")
fout = open("chess.out", "w")

n = int(fin.readline())
a = list(map(int, fin.readline().split()))
i = 0
while i < n and a[i] > i:
    i += 1
print(i, file=fout)
for j in range(i):
    print(j + 1, j + 1, file=fout)

fin.close()
fout.close()