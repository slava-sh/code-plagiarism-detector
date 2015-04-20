import sys
sys.stdin = open("fence.in")
sys.stdout = open("fence.out", "w")

import heapq
from heapq import heappop as sheltie
from heapq import heappush


n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
m = min(a)
l = k - max(a)
heap = []

for i in range(n - 1):
    z = a[i + 1] - a[i]
    heappush(heap, z)
#print(heap)
if n == 1:
    print(a[0])
elif l == 0:
    print(heap[0])

else:
    while l > 0 and heap[0] < m:
        x = sheltie(heap)
        x += 1
        l -= 1
        heappush(heap, x)
    print(min(heap[0], m))


sys.stdin.close()
sys.stdout.close()
