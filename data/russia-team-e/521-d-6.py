import sys
sys.stdin = open('fence.in')
sys.stdout = open('fence.out','w')

def check(x):
    count=0
    for i in a:
        count+=i-count+(x-i+count if i-count<x else 0)
    return count

n,k=map(int,input().split())
a = list(map(int,input().split()))
a.sort()
if sum(a)<=k:
    print(min(a))
else:
    ans = k//n+1
    while check(ans)>k:
        ans-=1
    print(ans)
sys.stdout.close()