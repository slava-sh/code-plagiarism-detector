inp = open('sochi.in')
outp = open('sochi.out', 'w')

n, d = tuple(map(int, inp.readline().split()))
a = list(map(int, inp.readline().split()))

a.sort()
res = 0
edges = 0
added = 0

if n == 1:
    res = a[0]
else:
    for val in a[::-1]:
        if val >= 3*d:
            res += val - 2*d
            added += 1
        elif edges < 2 and val >= d:
            res += val - d
            print(res)
            edges += 1
            added += 1
    if added == 0:
        res = a[-1]
    else:
        res += (2 - edges) * d

res = max(res, a[-1])


outp.write(str(res))

inp.close()
outp.close()
