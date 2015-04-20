def readdata():
    global n, k, a
    fread = open('fence.in', 'r')
    n, k = [int(x) for x in fread.readline().split()]
    a = [int(x) for x in fread.readline().split()]
    

def may(x):
    pokr = 0
    for i in range(n):
        if a[i] < x:
            return False
        pokr = max(pokr + x, a[i])
        if pokr > k:
            return False
    return True

    
def solve():
    a.sort()
    l = -1
    r = k // n + 2
    while r - l > 1:
        x = (l + r) // 2
        if may(x):
            l = x
        else:
            r = x
    fwrite = open('fence.out', 'w')
    print(l, file = fwrite)
    fwrite.close()


readdata()
solve()