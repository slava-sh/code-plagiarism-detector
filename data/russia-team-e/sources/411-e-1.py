fin = open('numbers.in', 'r')
fout = open('numbers.out', 'w')


n = int(fin.readline())
h = []
u = 0
v = 0
for i in range(n):
    c, k = [str(i) for i in fin.readline().split()]
    l = [c]
    k = int(k)
    for i in range(k):
        a = fin.readline()
        l.append(a)
    h.append(l)
m = int(fin.readline())
noms = []
for i in range(m):
    nom = fin.readline()
    noms.append(nom)
for i in range(len(noms)):
    u = 0
    v = 0
    for j in range(len(h)):
        if h[j][0] == noms[i][0:len(h[j][0])]:
            u = 1
            c = h[j][0]
            for t in range(1, len(h[j])):
                if h[j][t] == noms[i][len(c):len(h[j][t]) + len(c)]:
                    v = 1
                    k = h[j][t]
                    ost = len(noms[i]) - len(c) - len(k)
                    ost1 = []
                    if ost == 3:
                        if noms[i][len(c) + len(k)::][0] == '0':
                            print('Incorrect', file = fout)
                            break
                        else:
                            ost1.append(noms[i][len(c) + len(k)::])
                    elif ost == 4:
                        if noms[i][len(c) + len(k)::][0] == '0':
                            print('Incorrect', file = fout)
                            break                      
                        else:
                            ost1.append(noms[i][len(c) + len(k):len(c) + len(k) + 2])
                            ost1.append(noms[i][len(c) + len(k) + 2::])
                    elif ost == 5:
                        if noms[i][len(c) + len(k)::][0] == '0':
                            print('Incorrect', file = fout)
                            break
                        else:
                            ost1.append(noms[i][len(c) + len(k):len(c) + len(k) + 3])
                            ost1.append(noms[i][len(c) + len(k) + 3::])
                    elif ost == 6:
                        if noms[i][len(c) + len(k)::][0] == '0':
                            print('Incorrect', file = fout)
                            break                       
                        else:
                            ost1.append(noms[i][len(c) + len(k):len(c) + len(k) + 2])
                            ost1.append(noms[i][len(c) + len(k) + 2:len(c) + len(k) + 4])  
                            ost1.append(noms[i][len(c) + len(k) + 4::])
                    elif ost == 7:
                        if noms[i][len(c) + len(k)::][0] == '0':
                            print('Incorrect', file = fout)
                            break                       
                        else:
                            ost1.append(noms[i][len(c) + len(k):len(c) + len(k) + 3])
                            ost1.append(noms[i][len(c) + len(k) + 3:len(c) + len(k) + 5])  
                            ost1.append(noms[i][len(c) + len(k) + 5::])
                    print('+' + c + '(' + k + ')' + '-'.join(list(map(str, ost1))), file = fout)
    if u == 0:
        print('Incorrect', file = fout)
    elif u == 1 and v == 0:
        print('Incorrect', file = fout)
