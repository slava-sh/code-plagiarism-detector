import sys
sys.stdin = open("prizes.in")
sys.stdout = open("prizes.out","w")
n,m = map(int,input().split())
if min(n,m)==1:
    print((max(n,m)-1)//4+(1 if (max(n,m)-1)%4>=2 else 0))
elif min(n,m)<=2:
    print(0)
else:
    print((min(n,m)-1)//4+(1 if (min(n,m)-1)%4>=2 else 0))
sys.stdout.close()