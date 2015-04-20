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
rv = rp = 0

for i in a:
    if okv(i) and not okp(i):
        cv += 1
    elif not okv(i) and okp(i):
        cp += 1
    elif okv(i) and okp(i):
        cnt += 1

if n <= m:
    rv = cv + cnt // 2
    rp = cp + (cnt + 1) // 2
    if rv > rp:
        print("Vasya", file=fout)
    elif rv < rp:
        print("Petya", file=fout)
    else:
        print("Draw", file=fout)
    exit()

if cnt <= m:
    m -= cnt
    rv = cnt // 2
    rp = (cnt + 1) // 2
    cur = cnt % 2
    rp1 = rv1 = 0
    while m > 0:
        m -= 1
        if cp > rp1 and (cur == 0 or cv <= rv1):
            rp1 += 1
        elif cv > rv1:
            rv1 += 1
        cur = 1 - cur
    rv += rv1
    rp += rp1
    if rv > rp:
        print("Vasya", file=fout)
    elif rv < rp:
        print("Petya", file=fout)
    else:
        print("Draw", file=fout)
    exit()
else:
    rv = m // 2
    rp = (m + 1) // 2
    if rv > rp:
        print("Vasya", file=fout)
    elif rv < rp:
        print("Petya", file=fout)
    else:
        print("Draw", file=fout)
    exit()

if rv > rp:
    print("Vasya", file=fout)
elif rv < rp:
    print("Petya", file=fout)
else:
    print("Draw", file=fout)

fin.close()
fout.close()