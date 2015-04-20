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
    ans = 0
    l=0
    r=k//n
    while r-l>1:
        ans=(l+r)//2
        if check(ans)<=k:
            l=ans
        else:
            r=ans
    if check(r)<=k:print(r)
    else:
        print(l)
sys.stdout.close()