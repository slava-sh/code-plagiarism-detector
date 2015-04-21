res = 0
n, k, c, d = list(map(int, input().split(' ')))
m = n - 1

a = []
b = []
mas = []
pref = []

for i in range(n):
    a.append(0)
    b.append(0)
    
for i in range(m):
    mas.append(0)
    pref.append(0)
    
for i in range(n):
    a[i], b[i] = map(int, input().split(' '))
    res += d * (b[i] - a[i])

for i in range(m):
    mas[i] = a[i + 1] - b[i]
    pref[i] = pref[i - 1] + mas[i]

mas.sort()

if n == 1:
    print(d * (b[0] - a[0]))
else:
    r = n - 1
    l = 0
    while r - l > 2:
        mid1 = l + (r - l) // 3
        mid2 = l + ((r - l) // 3) * 2

        amount = mid1
        ch1 = c * ((n - amount) // k - 1 + (bool)((n - amount) % k)) + d * pref[amount - 1] 

        amount = mid2
        ch2 = c * ((n - amount) // k - 1 + (bool)((n - amount) % k)) + d * pref[amount - 1] 
        
        if ch1 < ch2:
            r = mid2
        else:
            l = mid1

    amount = r
    ans = res + c * ((n - amount) // k - 1 + (bool)((n - amount) % k)) + d * pref[amount - 1] 

    while l <= r:
        amount = l
        ch1 = c * ((n - amount) // k - 1 + (bool)((n - amount) % k)) + d * pref[amount - 1] 
        ans = min(ans, res + ch1)
        l += 1
        
    print(ans)

