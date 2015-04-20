inp = open('prizes.in', 'r')
out = open('prizes.out', 'w')
m, n =list(map(int, inp.readline().split()))
if m % 2  == 0 and n % 2 != 0:
    x = m
elif n % 2  == 0 and m % 2 != 0:
    x = n
elif m % 2  == 0 and n % 2 == 0:
    x = min(n, m)
else:
    x = m + n - 1

if x % 4 == 0:
    y = x / 4
elif x % 4 == 3:
    y = (x + 1) / 4
else:
    y = x // 4
print(int(y), file = out)
inp.close()
out.close()