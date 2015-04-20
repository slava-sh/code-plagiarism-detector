def okv(x):
    return l1 <= x <= r1

def okp(x):
    return l2 <= x <= r2

fin = open("game.in", "r")
fout = open("game.out", "w")

n, m = map(int, fin.readline().split())
l2, r2 = map(int, fin.readline().split())
l1, r1 = map(int, fin.readline().split())
a = list(map(int, fin.readline().split()))
cv = cp = 0
cnt = 0
r = [0, 0]

for i in a:
    if okv(i) and not okp(i):
        cv += 1
    elif not okv(i) and okp(i):
        cp += 1
    elif okv(i) and okp(i):
        cnt += 1

cur = 0
while m > 0 and cv + cp + cnt > 0:
    if cnt > 0:
        m -= 1
        cnt -= 1
        r[cur] += 1
    elif cur == 0 and cp > 0:
        cp -= 1
        r[cur] += 1
        m -= 1
    elif cur == 1 and cv > 0:
        cv -= 1
        r[cur] += 1
        m -= 1
    cur = 1 - cur

if r[0] < r[1]:
    print("Vasya", file=fout)
elif r[0] > r[1]:
    print("Petya", file=fout)
else:
    print("Draw", file=fout)

fin.close()
fout.close()