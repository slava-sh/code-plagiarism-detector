inp = open('prizes.in', 'r')
out = open('prizes.out', 'w')
m, n =list(map(int, inp.readline().split()))
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