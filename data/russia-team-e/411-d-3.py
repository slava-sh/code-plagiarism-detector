fin = open('fence.in', 'r')
fout = open('fence.out', 'w')

n, k = [int(i) for i in fin.readline().split()]
a = [int(i) for i in fin.readline().split()]
x = 0
a.sort()
if n > 1:
    i = 0
    l = a[0]
    x = min(a[i], (k - l) // (n - i - 1))
    l += x
    i += 1
    while i < n - 1:
        if x < a[i] - l:
            x = min(a[i] - l, (k - l) // (n - i - 1))
        l += x
        i += 1
    print(x, file = fout)
else:
    print(a[0], file = fout)
fin.close()
fout.close()