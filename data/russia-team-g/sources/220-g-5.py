n, m = map(int, open('prizes.in').read().split())
mini = min(n, m) - 1
if not mini:
    mini = max(n, m) - 1
ans = 0
if mini - 2 > 0:
    ans += 1
    ans += (mini - 2) // 4
if mini -2 == 0:
    ans = 1
print(ans, file = open('prizes.out', 'w'))
    
