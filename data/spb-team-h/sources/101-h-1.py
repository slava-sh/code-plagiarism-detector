infile = open('names.in')
outfile = open('names.out', 'w')
n = int(infile.readline())
ls = [infile.readline().rstrip().split() for i in range(n)]
d = dict()
lool = [[0, 0, 0] for i in range(n)]
for i in range(n):
    for j in  range(3):
        if ls[i][j] in d.keys():
            lool[i][j] = 1
            lool[d[ls[i][j]][0]][d[ls[i][j]][1]] = 1
        else:
            d[ls[i][j]] = (i, j)
ans = []
#print(lool)
for i in range(n):
    if lool[i][0] == 0:
        ans.append(' '.join(ls[i]))
    else:
        ans.append(' '.join([ls[i][2], ls[i][0], ls[i][1]]))
ans.sort()
for i in range(n):
    print(ans[i], file = outfile)