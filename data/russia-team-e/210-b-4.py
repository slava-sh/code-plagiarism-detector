inp = open('che.in', 'r')
out = open('che.out', 'w')
n, r = list(map(int, inp.readline().split()))
lis = list(map(int, inp.readline().split()))
s = 0
inp.close()
lis1 = [[[],0]] * n 
for i in range(1, n):
    h = lis1[i-1][1]
    b = True
    if lis[i] - r > lis[i - 1]:
        h += 1
    else:
        b = False
    ji = lis1[i - 1][0]
    if len(ji):
        o = 0
        while o < len(ji) and ji[o] < lis[i] - r:
            h += 1
            o += 1
    s += h
    lis1[i][0] = ji
    lis1[i][1] = h
    if not b:
        lis1[i][0].append(lis[i-1])
    
print(s, file = out)
out.close()