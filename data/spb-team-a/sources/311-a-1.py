fin = open('abcd.in')
fout = open('abcd.out', 'w')
n = int(fin.readline())
for i in range(n):
    s = fin.readline()
    a = int(s[:2])
    b = int(s[2:])
    if (a * a + b * b) % 7 == 1:
        print('YES', file = fout)
    else:
        print('NO', file = fout)
fin.close()
fout.close()