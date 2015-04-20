import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out", 'w')

n, d = map(int, input().split())
inp = list(map(int, input().split()))

patch = []
for i in range(n):
    if inp[i] >= d:
        patch.append(inp[i])
        
n = len(patch)
patch.sort(reverse=True)

m = 0
for i in range(n):
    if patch[i] > 3 * d:
        m += 1
        
if n - m < 2:
    print(sum(patch) - 2 * (n - 1) * d)
else:
    print(sum(patch[:m + 2]) - 2 * (m + 1) * d)