import sys
#sys.stdin = open('game.in', 'r')
#sys.stdout = open('game.out', 'w')
n, m = [int(t) for t in input().split()]
l1, r1 = [int(t) for t in input().split()]
l2, r2 = [int(t) for t in input().split()]
collum = [int(t) for t in input().split()]
collum.sort()
def bins(x):
    l = -1
    r = n - 2
    while r - l > 1:
        q = (r + l) // 2
        if collum[q] < x:
            l = q
        else:
            r = q
    return r
Petya = 0
Vasya = 0
rings1 = m
rings2 = m
if r1 > r2:
    r3 = r2
else:
    r3 = r1
if l1 > l2:
    l3 = l1
else:
    l3 = l2
k = 0
for a in range(l3, r3 + 1):
        if a == collum[bins(a)]:
            collum.remove(a)
            if k == 0 and rings1 > 0:
                k = 1
                Petya += 1
                rings1 -= 1
            elif rings2 > 0:
                k = 0
                Vasya += 1
                rings2 -= 1

if rings1 > 0 and rings2 > 0:
    if l1 < l3 and rings1 > 0:
        for a in range(l1, l3):
            if a == collum[bins(a)] and rings1 > 0:
                Petya += 1
                rings1 -= 1
    if r1 > r3 and rings1 > 0:
        for a in range(r3 + 1, r1 + 1):
            if a == collum[bins(a)] and rings1 > 0:
                Petya += 1
                rings1 -= 1
    if l2 < l3 and rings2 > 0:
        for a in range(l2, l3):
            if a == collum[bins(a)] and rings2 > 0:
                Vasya += 1
                rings2 -= 1
    if r2 > r3 and rings2 > 0:
        for a in range(r3 + 1, r2 + 1):
            if a == collum[bins(a)] and rings2 > 0:
                Vasya += 1
if Petya > Vasya:
    print('Petya')
elif Petya < Vasya:
    print('Vasya')
else:
    print('Draw')
