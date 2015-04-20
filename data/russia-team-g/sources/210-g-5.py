inp = open('prizes.in', 'r')
out = open('prizes.out', 'w')
m, n =list(map(int, inp.readline().split()))
if m % 2  == 0 and n % 2 != 0:
    x = m //4
elif n % 2  == 0 and m % 2 != 0:
    x = n // 4
elif m % 2  == 0 and n % 2 == 0:
    x = min(n, m) // 4
else:
    x=(m+n)//4+ (m+n)%4//2

 
print(int(x), file = out)
inp.close()
out.close()