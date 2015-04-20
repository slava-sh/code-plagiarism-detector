import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out", 'w')

n, d = map(int, input().split())
inp = list(map(int, input().split()))

patch = []
for i in range(n):
    if inp[i] > d:
        patch.append(inp[i])
        
n = len(patch)
patch.sort(reverse=True)

m = 0
for i in range(n):
    if patch[i] >= 3 * d:
        m += 1
        
k = 0
for i in range(m, n):
    if patch[i] > 2 * d:
        k += 1
    if k == 2:
        break
    
if m == k == 0:
    print(path[0])
else:
    print(sum(patch[:m + k]) - 2 * (m + k - 1) * d)