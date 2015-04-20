f = open("game.in", "r")

n, m    = [int(i) for i in f.readline().split()]
l1, r1  = [int(i) for i in f.readline().split()]
l2, r2  = [int(i) for i in f.readline().split()]

h = [0] * n
h = [int(i) for i in f.readline().split()]

PV = 0

VP = [0] * 2

for i in range(n):
    if l1 <= h[i] <= r1: VP[0] += 1
    if l2 <= h[i] <= r2: VP[1] += 1

PV = abs(VP[1] - VP[0])
VP[0] = VP[0] - PV
VP[1] = VP[1] - PV

f = open("game.out", "w")

hod = 0

kol = [0] * 2

while m > 0 and PV > 0:
    PV -= 1
    m -=  1
    kol[hod] += 1
    hod = (hod - 1) * (-1)

hod = (hod - 1) * (-1)

while m > 0 and VP[1] > 0 and VP[0] > 0:
    VP[hod] -= 1
    kol[hod] += 1
    m -= 1
    hod = (hod - 1) * (-1)

if m != 0:
    if VP[0] != 0: kol[0] += min(m, VP[0])
    else: kol[1] += min(m, VP[1])

if kol[0] == kol[1]: f.write('Draw')
if kol[0] >  kol[1]: f.write('Petya')
if kol[0] <  kol[1]: f.write('Vasya')







