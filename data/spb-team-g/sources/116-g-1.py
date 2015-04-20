fin = open('merlin.in')
n = int(fin.readline().strip())
mass = list(map(int, fin.readline().split()))
s = sum(mass)
mass.sort()

beg, end = -1, n
while beg + 1 != end:
    mid = (beg + end) // 2
    x = s / (n - mid)
    beg_x, end_x = 0, n
    while beg_x + 1 != end_x:
        mid_x = (beg_x + end_x) // 2
        if mass[mid_x] <= x:
            beg_x = mid_x
        else:
            end_x = mid_x
    if mid < n - beg_x - 1:
        beg = mid
    else:
        end = mid

print(end, file=open('merlin.out', 'w'))
