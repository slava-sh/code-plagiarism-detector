import sys
sys.stdin = open('names.in', 'r')
sys.stdout = open('names.out', 'w')
n = int(input())
namelist = []
needlist = []
outlist = []
for a in range(n):
    needlist.extend(input().split())
for a in range(n):
    a *= 3
    if needlist[a] in namelist:
        outlist.append([needlist[a + 2], needlist[a], needlist[a + 1]])
    elif needlist.count(needlist[a]) > 1:
        namelist.append(needlist[a + 1])
        outlist.append([needlist[a + 2], needlist[a], needlist[a + 1]])
    else:
        outlist.append([needlist[a], needlist[a + 1], needlist[a + 2]])
outlist.sort(key=lambda x: x[0])
for a in outlist:
    print(a[0], a[1], a[2])