import sys
sys.stdin = open("prizes.in")
sys.stdout = open("prizes.out", "w")

nm = tuple(map(int, input().split()))
n = min(nm)
m = max(nm)
if n == 1:
    print((m + 1) // 4)
elif n == 2:
    print(0):  
else:
    print(1)


sys.stdin.close()
sys.stdout.close()
