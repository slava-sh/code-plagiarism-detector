import sys
sys.stdin = open('dunes.in', 'r')
sys.stdout = open('dunes.out', 'w')
n, m = [int(t) for t in input().split()]
winds = []
changelist = []
for a in range(n):
    l, r, x = [int(t) for t in input().split()]
    winds.append([l, r, x])
needlist = []
outlist = [0] * m
for a in range(m):
    needlist.append(int(input()))
for a in range(n):
    for b in range(m):
        if needlist[b] >= winds[a][0] and needlist[b] <= winds[a][1]:
            if (needlist[b] - winds[a][0]) % 2 == 0:
                outlist[b] += winds[a][2]
            else:
                outlist[b] -= winds[a][2]
for a in outlist:
    print(a)