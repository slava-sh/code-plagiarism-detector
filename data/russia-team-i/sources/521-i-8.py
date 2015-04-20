import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out","w")
n,d = map(int,input().split())
a = map(int,input().split())
a = list(a)
try:
    if n==1:
        print(*a)
        exit(0)
    a.sort()
    ans = 0
    i = 0
    while i<n and a[i]<3*d: i+=1
    if i == n:
        if i-1>=0 and a[i-1]>2*d:
            ans+=a[i-1]-d
        if i-2>=0 and a[i-2]>2*d:
            ans+=a[i-2]-d    
        print(max(ans,a))
        exit(0)
    tose = []
    ends = 0
    if i-1>=0 and a[i-1]>2*d:
        ends+=1
        ans+=a[i-1]-d
    if i-2>=0 and a[i-2]>2*d:
        ends+=1
        ans+=a[i-2]-d
    for j in range(i,min(n,i+2-ends)):
        ans+=a[j]-d
    for j in range(i+2-ends,n):
        ans+=a[j]-2*d
    print(max(max(a),ans))
    sys.stdout.close()
except:
    print(max(a))