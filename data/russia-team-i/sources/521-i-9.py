import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out","w")
def solve1(n,d,a):
    if n==1:
            print(*a)
            exit(0)
    a.sort()
    ans = 0
    i = 0
    while i<n and a[i]<3*d: i+=1
    if i == n:
        if i-1>=0 and a[i-1]>d:
            ans+=a[i-1]-d
        if i-2>=0 and a[i-2]>d:
            ans+=a[i-2]-d    
        return max(ans,max(a))
    tose = []
    ends = 0
    if i-1>=0 and a[i-1]>d:
        ends+=1
        ans+=a[i-1]-d
    if i-2>=0 and a[i-2]>d:
        ends+=1
        ans+=a[i-2]-d
    for j in range(i,min(n,i+2-ends)):
        ans+=a[j]-d
    for j in range(i+2-ends,n):
        ans+=a[j]-2*d
    return max(max(a),ans)

def solve2(n,d,a):
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
        return max(ans,max(a))
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
    return max(max(a),ans)
    
    
n,d = map(int,input().split())
a = map(int,input().split())
a = list(a)
try:
    print(max(max(a),solve1(n,d,a),solve2(n,d,a)))
except:
    print(max(a))
sys.stdout.close()