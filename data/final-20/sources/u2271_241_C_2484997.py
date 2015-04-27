from math import *
[h1, h2, n] = map(int, raw_input().split())
v = []
x1 = []
x2 = []
b = []
tm = [[-1] * 100001, [-1] * 100001]
for i in xrange(n):
    ttt = raw_input().split()
    v.append(int(ttt[0]))
    x1.append(int(ttt[2]))
    x2.append(int(ttt[3]))
    for x in xrange(int(ttt[2]), int(ttt[3]) + 1):
        tm[int(ttt[1]=='T')][x] = i
    b.append(int(ttt[1]=='T'))
maxscore = 0
for i in xrange(-n, n+1):
    hit = [False] * n
    h = i * 100 + (h2 if i % 2 == 0 else 100 - h2)
    score = 0
    for j in xrange(min(i + 1, 1), max(i + 1, 1)):
        y = j * 100
        x = (float(y) - h1) / (h - h1) * 100000
        xc = int(ceil(x) + 0.1)
        xf = int(floor(x) + 0.1)
        bank = int(j % 2 != 0)
        if (tm[bank][xc] != -1 and tm[bank][xc] == tm[bank][xf]):
            m = tm[bank][xc]
            if hit[m]:
                score = 0
                break
            hit[m] = True
            score += v[m]
        else:
            score = 0
            break
    maxscore = max(maxscore, score)
print maxscore
