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
heap2 = []
for i in range(n - 1):
    z = a[i + 1] - a[i]
    heappush(heap, z)
    heappush(heap2, z* (-1))
#print(heap)
if n == 1:
    print(a[0])

else:
    while l > 0 and heap[0] < m:
        x = sheltie(heap)
        x1 = sheltie(heap2)
        x += 1
        l -= 1
        x1 -= 1
        heappush(heap, x)
        heappush(heap2, x1)
   # print(heap)
   # print(heap2)
    if heap[0] != max(heap):
        while heap[0] != max(heap) - 1:
            x = sheltie(heap)
            x1  = sheltie(heap2)
            x1 += 1
            x += 1
            heappush(heap, x)
            heappush(heap2, x1)
    print(min(heap[0], m))
   # print(heap)


sys.stdin.close()
sys.stdout.close()
