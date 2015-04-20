import sys
sys.stdin = open('prizes.in')
sys.stdout = open('prizes.out', 'w')


from math import ceil
n, m = map(int, input().split())
m, n = min(m, n), max(m, n)
if m == 1:
    print(ceil((n - 2) / 4))
elif m > 3:
    print(1)
else:
    print(ceil((m - 2) / 4))