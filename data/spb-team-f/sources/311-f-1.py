def gcd(n, m):
    global shtukovina
    if m == 0:
        shtukovina = n
        return 
    if n == 0:
        shtukovina = m
        return
    m = m % n
    m, n = n, m
    gcd(n, m)

    
def divs(n, nd):
    global shtukovina
    div = []
    d = 1
    summ = 10000000
    need1 = 1
    need2 = n
    while d * d <= n:
        if (n % d == 0) and (abs(n // d - d) < summ):
            gcd(n // d, d)
            #print(d, n // d)
            if shtukovina == nd:
                summ = abs(n // d - d)
                need1 = d
                need2 = n // d
        d += 1
    return [need1, need2]


fin = open('gcm.in')
fout = open('gcm.out', 'w')
n, m = map(int, fin.readline().split())
shtukovina = 0
gcd(n, m)
d = shtukovina
x = n * m // d
a = divs(n * m, d)
print(a[0], a[1], file = fout)
fin.close()
fout.close()
