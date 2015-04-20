import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out","w")
n,d = map(int,input().split())

a = map(int,input().split())
a = list(a)
a.sort()
i = 0
while i<n and a[i]<=d: i+=1
if i!=n:ans = sum(a[i:]) - 2*d*(n-i)+2*d
else: ans = -2
print(max(max(a),ans))
sys.stdout.close()