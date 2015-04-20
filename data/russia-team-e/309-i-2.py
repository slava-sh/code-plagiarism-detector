inp = open('sochi.in')
outp = open('sochi.out', 'w')

n, d = tuple(map(int, inp.readline().split()))
a = list(map(int, inp.readline().split()))

a.sort()
res = 0
shorts = []
longs = []

if n == 1:
    res = a[0]
else:
    for val in a[::-1]:
        if val >= 3*d:
            longs.append(val)
        elif len(shorts) < 2 and val >= d:
            shorts.append(val)
        else:
            break
    if len(shorts) + len(longs) < 2:
        res = a[-1]
    elif len(shorts) == 0:
        res = sum(longs) - 2*d*(len(longs) - 1)
    elif len(shorts) == 1:
        if len(longs) == 1:
            res = longs[0] + shorts[0] - 2*d
        else:
            if shorts[0] > 2*d:
                res = sum(longs) + shorts[1] - 2*d*len(longs)
            else:
                res = sum(longs) - 2*d*(len(longs) - 1)
    else:
        if len(longs) == 0:
            res = sum(shorts) - 2*d
        elif len(longs) == 1:
            res = max(longs[0] + sum(shorts) - 4*d, longs[0] + shorts[0] - 2*d)
        else:
            res = max(sum(longs) + sum(shorts) - 2*d*(len(longs) + 1), sum(longs) + shorts[0] - 2*d*len(longs), sum(longs) - 2*d*(len(longs) - 1))

res = max(res, a[-1])

#print(shorts, longs)
#print(res)
outp.write(str(res))

inp.close()
outp.close()
