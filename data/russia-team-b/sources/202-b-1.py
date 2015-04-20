import sys
sys.stdin = open('che.in')
sys.stdout = open('che.out', 'w')

n, r = map(int, input().split())
d = list(map(int, input().split()))
res = 0
i = j = 0
while i < n:
    if d[j] - d[i] <= r:
        j += 1
        if j >= n:
            break
    else:
        res += n - j
        i += 1
print(res)