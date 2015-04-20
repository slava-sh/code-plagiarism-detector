import sys
sys.stdin = open("prizes.in")
sys.stdout = open("prizes.out", "w")

nm = tuple(map(int, input().split()))
n = min(nm)
m = max(nm)
if n == 1:
    if m == 1:
        print(0)
    else:
        print((m + 1) // 4)
else:
    print((n + 1) // 4)


sys.stdin.close()
sys.stdout.close()
