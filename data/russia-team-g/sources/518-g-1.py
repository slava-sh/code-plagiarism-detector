fin = open("prizes.in", "r")
fout = open("prizes.out", "w")
n, m = map(int, fin.readline().rstrip().split())
if min(n, m) > 2:
    fout.write("1\n")
elif min(n, m) == 2:
    fout.write("0\n")
else:
    if (n == 1):
        fout.write(str((m + 1) // 4) + "\n")
    elif (m == 1):
        fout.write(str((n + 1) // 4) + "\n")
fin.close()
fout.close()