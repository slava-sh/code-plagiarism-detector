fin = open('numbers.in')
fout = open('numbers.out', 'w')
n = int(fin.readline().strip())
set_first = set()
conn = dict()
for i in range(n):
    fr, m = map(int, fin.readline().split())
    set_first.add(fr)
    conn[fr] = set()
    for j in range(m):
        conn[fr].add(fin.readline().strip())
n = int(fin.readline().strip())
for k in range(n):
    s = fin.readline().strip()
    if s[0] == '0':
        print('Incorrect', file = fout)
        continue
    check = False
    for i in range(1, 4):
        if s[i] != '0' and int(s[:i]) in set_first:
            fr = int(s[:i])
            for j in range(i + 3, i + 6):
                if s[j] != '0' and s[i:j] in conn[fr]:
                    print('+', fr, '(', s[i:j], ')', sep = '', end = '', file = fout)
                    ost = 11 - j
                    if ost == 3:
                        print(s[j:], file = fout)
                    elif ost == 4:
                        print(s[j:j + 2], s[j + 2:], sep = '-', file = fout)
                    elif ost == 5:
                        print(s[j:j + 3], s[j + 3:], sep = '-', file = fout)
                    elif ost == 6:
                        print(s[j:j + 2], s[j + 2:j + 4], s[j + 4:], sep = '-', file = fout)
                    else:
                        print(s[j:j + 3], s[j + 3:j + 5], s[j + 5:], sep = '-', file = fout)
                    check = True
                    break
            else:
                break
    if not check:
        print('Incorrect', file = fout)
fout.close()