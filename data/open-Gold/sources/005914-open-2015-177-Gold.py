
res = 0
n, k, c, d = list(map(int, input().split(' ')))
m = n - 1

a = []
b = []
mas = []

for i in range(n):
    a.append(0)
    b.append(0)

    
for i in range(m):
    mas.append(0)

for i in range(n):
    a[i], b[i] = map(int, input().split(' '))
    res += d * (b[i] - a[i])

for i in range(m):
    mas[i] = a[i + 1] - b[i]

mas.sort()

if n % k == 0:
    ans = c * (n // k - 1) + res
else:
    ans = c * (n // k) + res
    
for amount in range(n):
    curr = c * ((n - amount) // k + (bool)(n - amount) % k - 1)
    for j in range(amount):
        curr += d * mas[j]
    ans = min(ans, curr + res)

print(ans)

