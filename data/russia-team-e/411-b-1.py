fin = open('che.in', 'r')
fout = open('che.out', 'w')

n, r = [int(i) for i in fin.readline().split()]
a = [int(i) for i in fin.readline().split()]
ans = 0
for i in range(n):
    lo = -1
    hi = n
    mid = (lo + hi) // 2
    while lo + 1 != hi:
        if a[i] + r + 1 <= a[mid]:
            hi = mid
        else:
            lo = mid
        mid = (lo + hi) // 2 
    ans += n - hi
print(ans, file = fout)

fin.close()
fout.close()