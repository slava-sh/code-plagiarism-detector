fin = open('game.in')
fout = open('game.out', 'w')
n, m = map(int, fin.readline().split())
l1, r1 = map(int, fin.readline().split())
l2, r2 = map(int, fin.readline().split())
mas = [int(i) for i in fin.readline().split()]
ob = 0
petya = 0
vasya = 0
p = 0
v = 0
for i in mas:
    if i >= max(l1, l2) and i <= min(r1, r2):
        ob += 1
    elif (i < l1 and i >= l2) or (i > r1 and i <= r2):
        vasya += 1
    elif (i < l2 and i >= l1) or (i > r2 and i <= r1):
        petya += 1
#print(petya, vasya, ob, file = fout)
for i in range(m):
    if i % 2 == 0:
        if ob != 0:
            ob -= 1
            p += 1
        elif petya != 0:
            petya -= 1
            p += 1
        else:
            break
    else:
        if ob != 0:
            ob -= 1
            v += 1
        elif vasya != 0:
            vasya -= 1
            v += 1
        else:
            break
if p + min(petya, m - i - 1) > v + min(vasya, m - i - 1):
    print('Petya', file = fout)
elif p + min(petya, m - i - 1) < v + min(vasya, m - i - 1):
    print('Vasya', file = fout)
else:
    print('Draw', file = fout)
fin.close()
fout.close()