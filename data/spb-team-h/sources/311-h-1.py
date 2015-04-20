fin = open('names.in')
fout = open('names.out', 'w')
n = int(fin.readline())
names = []
was = [False] * n
for i in range(n):
    x = fin.readline().split()
    names.append(x)
for i in range(n):
    if not was[i]:
        was[i] = True
        curr = []
        for j in range(i + 1, n):
            if (names[i][0] == names[j][0]) or (names[i][0] == names[j][1]):
                names[i][0], names[i][1], names[i][2] = names[i][2], names[i][0], names[i][1]
                curr.append(j)
                was[j] = True
            elif (names[i][1] == names[j][0]) or (names[i][1] == names[j][1]):
                curr.append(j)
                was[j] = True                
        for j in curr:
            if names[i][1] == names[j][0]:
                names[j][0], names[j][1], names[j][2] = names[j][2], names[j][0], names[j][1]
names.sort()
for i in range(n):
    print(*names[i], file = fout)
fin.close()
fout.close()