fin = open('sochi.in', 'r')
fout = open('sochi.out', 'w')

n, d = [int(i) for i in fin.readline().split()]
a = [int(i) for i in fin.readline().split()]
b = 0
e = 0
c = 0
cnt = 0
if n > 1:
    for i in range(n):
        if a[i] >= 3 * d:
            c += a[i] - 2 * d
            cnt += 1
        elif a[i] > d:
            if a[i] - d > e:
                if a[i] - d > b:
                    e = b
                    b = a[i] - d
                else:
                    e = a[i] - d
            cnt += 1
    if cnt == 0:
        print(max(a), file = fout)
    elif b == 0 and e == 0:
        print(c + 2 * d, file = fout)
    elif b == 0 or e == 0:
        print(e + b + c + d, file = fout)    
    else:
        print(b + c + e, file = fout)
else:
    print(a[0], file = fout)

fin.close()
fout.close()