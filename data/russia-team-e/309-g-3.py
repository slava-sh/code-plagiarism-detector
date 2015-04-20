inp = open('prizes.in')
outp = open('prizes.out', 'w')

n, m = tuple(map(int, inp.readline().split()))
n, m = sorted((n, m))

if 2 in (n, m):
    res = 0
elif (n, m) == (1, 1):
    res = 0
elif 1 in (n, m):
    res = (m - 3) // 4 + 1
else:
    res = (n - 3) // 4 + 1

outp.write(str(res))
#print(res)

inp.close()
outp.close()
