import sys
sys.stdin = open('fence.in')
sys.stdout = open('fence.out','w')

def check(x):
    count=0
    for i in a:
        count+=max(i-count,0)+(x-i+count if i-count<x else 0)
    return count

n,k=map(int,input().split())
a = list(map(int,input().split()))
a.sort()
if sum(a)<=k:
    print(min(a))
else:
    ans = 0
    l=-1
    r=k//n+1
    while r-l>1:
        ans=(l+r)//2
        dd = check(ans)
        if dd<=k:
            l=ans
        else:
            r=ans
    while(check(l)<=k):
        l+=1
    #if check(r)<=k:print(r)
    #else:
    print(l-1)
sys.stdout.close()