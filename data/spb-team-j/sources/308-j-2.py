import sys
sys.stdin = open('seq.in', 'r')
sys.stdout = open('seq.out', 'w')
n, h = [int(t) for t in input().split()]
nlist = [int(t) for t in input().split()]
minsum = 10 ** 20
for a in range(n):
    if nlist[a] < 2:
        nowsum = 0
        if a < len(nlist) - h + 1:
            for b in range(h):
                if nlist[a + b] > b + 1:
                    break
                else:
                    if nlist[a + b] < b + 1:
                        nowsum += b + 1 - nlist[a + b]
                if nowsum < minsum and nowsum > 0 and b == h - 1:
                    minsum = nowsum
if minsum == 10 ** 20:
    minsum = -1
if h == 1:
    if 1 in nlist:
        minsum = 0
    elif 0 in nlist:
        minsum = 1
print(minsum)