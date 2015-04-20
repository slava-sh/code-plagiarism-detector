inp = open('prizes.in')
outp = open('prizes.out', 'w')

n, m = tuple(map(int, inp.readline().split()))

if min(n, m) == 1:
    if max(n, m) <= 2:
        res = 0
    else:
        res = max(max(n, m) - 3, 0) // 4 + 1
elif min(n, m) == 2:
    res = 0
else:
    res = (min(n, m) - 3) // 4 + 1

outp.write(str(res))

inp.close()
outp.close()
