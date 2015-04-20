import sys

sys.stdin = open("che.in")
sys.stdout = open("che.out", "w")

n, r = tuple(map(int, input().split()))
a = list(map(int, input().split()))

p1 = 0
p2 = 0
ans = 0
ok = True
while True:
    if p1 >= n:
        break
    while a[p2] - a[p1] <= r:
        p2 += 1
        if p2 >= n:
            break
    if p2 >= n or p1 >= n:
        break
    ans += n - p2
    p1 += 1
    
print(ans)
sys.stdin.close()
sys.stdout.close()
