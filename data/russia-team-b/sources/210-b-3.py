inp = open('che.in', 'r')
n, r = list(map(int, inp.readline().split()))
lis = list(map(int, inp.readline().split()))
s = 0
inp.close()
lis1 = [[[],0]] * n 
for i in range(1, n):
    h = lis1[i-1][1]
    if lis[i] - r > lis[i - 1]:
        h += 1
    else:
        lis1[i][0].append(lis[i-1])
    ji = lis1[i - 1][0]
    if len(ji):
        o = 0
        while ji[o] < lis[i] - r:
            h += 1
            ji.pop(o)
    s += h
    lis1[i][0] = ji
    lis1[i][1] = h
    
print(s, file = open('che.out', 'w'))