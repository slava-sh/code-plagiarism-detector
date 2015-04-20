import sys

filename = 'prizes'

sys.stdin = open(filename + '.in', 'r')
sys.stdout = open(filename + '.out', 'w')

n, m = list(map(int, input().split()))
if n > m:
    n, m = m, n
if n == 2 or m == 2:
    print(0)
elif n == 1 and m == 1:
    print(0)
elif n == 1:
    k = m // 4
    if m % 4 >= 3:
        k += 1
    print(k)
else:
    k = (n - 2) // 4
    if (n - 2) % 4 >= 1:
        k += 1
    print(k)
