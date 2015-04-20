from math import *
def gcd (a, b):
    if min (a, b) == 0:
        return a + b
    return gcd (max (a, b) % min (a, b), min (a, b))

def xyz(a, b):
    if b == 0:
        return 1
    res = a
    ans = 1
    while b > 1:
        if (b & 1):
            ans *= res
            b -= 1
        else:
            res *= res
            b >>= 1
    return ans * res


infile = open ("gcm.in")
outfile = open ("gcm.out", "w")
a , b = map(int, infile.readline().split())
lol = gcd(a, b);
olo = a * b // lol
h = olo // lol
g = h
w = 0
ans = []
for i in range(2, int(floor(sqrt(g))) + 1):
    l = 0
    r = int(ceil(log(10 ** 18) / log(i)))
    while (r - l > 1):
        m = (l + r) // 2
        if (g % xyz(i, m) == 0):
            l = m
        else:
            r = m
    w = xyz(i, l)
    g //= w
    if (w != 1):
        ans.append(w)
    if (g == 1):
        break
ans.append(g)
ans.sort(reverse=True)
ans1 = lol
ans2 = lol
for i in range(len(ans)):
    if (ans2 < ans1):
        ans2 *= ans[i]
    else:
        ans1 *= ans[i]
print(min(ans1, ans2), max(ans1, ans2), file=outfile)
outfile.close()