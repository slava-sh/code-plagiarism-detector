inp = open('fence.in')
outp = open('fence.out', 'w')

n, k = tuple(map(int, inp.readline().split()))
a = list(map(int, inp.readline().split()))
a.sort()


diff = [-1 for i in range(n - 1)]
last = a[0]
to_inc = k - a[-1]

if n == 1:
    #print(a[0])
    outp.write(str(a[0]))
else:
    for num, val in enumerate(a[1:]):
        diff[num - 1] = val - last
        last = val
    diff.sort()
    compressed = []
    for i in diff:
        if not compressed:
            compressed.append([i, 1])
        elif compressed[-1][0] == i:
            compressed[-1][1] += 1
        else:
            compressed.append([i, 1])

    #print(a, diff, compressed)
    while compressed[0][1] <= to_inc:
        compressed[0][0] += 1
        to_inc -= (compressed[0][1])
        if len(compressed) >= 2 and compressed[0][0] == compressed[1][0]:
            compressed[1][1] += compressed[0][1]
            del(compressed[0])
    res = (sum(i[0]*i[1] for i in compressed) + to_inc) // (n-1)
            
    #print(min(res, a[0]))
    outp.write(str(min(res, a[0])))

inp.close()
outp.close()
