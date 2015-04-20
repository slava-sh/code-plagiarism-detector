fin = open("names.in", 'r')
fout = open("names.out", 'w')

n = int(fin.readline().strip())
s = [fin.readline().strip().split(' ') for i in range(n)]

a = set()
#b = set()
name = set()
for i in range(n):
    if(s[i][0] in a): name.add(s[i][0])
    if(s[i][1] in a): name.add(s[i][1])
    a.add(s[i][0])
    a.add(s[i][1])
for i in range(n):
    if(s[i][0] in name):
        s[i][0], s[i][1], s[i][2] = s[i][2], s[i][0], s[i][1]

fa = [s[i][0] + ' ' + s[i][1] + ' ' + s[i][2] for i in range(n)]
fa.sort()
for i in fa:
    fout.write(i + "\n")

fin.close()
fout.close()
