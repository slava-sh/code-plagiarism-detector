import sys
sys.stdin = open('prizes.in')
sys.stdout = open('prizes.out', 'w')


from math import ceil
n, m = map(int, input().split())
mn = min(m, n)
if mn == 1:
    print(ceil((max(m, n) - 2) / 4))
else:
    print(ceil((mn - 2) / 4))