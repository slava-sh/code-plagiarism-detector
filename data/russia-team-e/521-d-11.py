import sys
sys.stdin = open('fence.in')
sys.stdout = open('fence.out','w')

def check(x):
    if x<0:
        return -1000000000000000000
    count=0
    for i in a:
        if count>=i:
            count+=x
        else:
            count+=i-count+(x-i+count if i-count<=x else 0)
       # print(count)
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
    if l-1 > a[0]:
        print(a[0])
    else:
        print(max(0,l-1))
sys.stdout.close()