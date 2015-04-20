f = open('abcd.in','rt')
f2 = open('abcd.out','wt')
l = f.readline().split()
n = int(l[0])
a=[]
for i in range(n):
	l = f.readline().split() 
	a.append(int(l[0]))
	b = int((a[i])/100)
	c = int(a[i])%100
	if (b**2 + c**2)%7==1:
		f2.write("YES\n")
	else:
		f2.write("NO\n")
