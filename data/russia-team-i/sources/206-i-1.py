import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out", "w")


n, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
i = 0
s = 0
l = len(a)
if n == 1:
    print(a[0])
elif n == 2:
    if a[0] > d:
        print(a[0] + a[1] - d * 2)
    else:
        print(a[1])
else:
    while i < l and a[i] < 3*d:
        i += 1
    if i == l:
        print(a[l - 1])
    else:
        if i >= 2 and a[i - 2] > d:
            s += a[i - 2] + a[i - 1] - 2 * d + sum(a[i:]) - 2 * d * (n - i)
        elif a[i - 1] > d:
          #  print('b')
            s += a[i - 1] - d + a[i] - d + sum(a[i + 1:]) - 2*d*(n - i - 1)
        else:
            s += a[i] - d + a[i + 1] - d + sum(a[i + 2:]) - 2 * d * (n - i - 2)
        print(s)
        

sys.stdin.close()
sys.stdout.close()
