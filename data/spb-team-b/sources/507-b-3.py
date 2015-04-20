f = open('chess.in','rt')
f2 = open('chess.out','wt')
l = f.readline().split()
n = int(l[0])
l = f.readline().split()
for i in range(len(l)):
	l[i] = int(l[i])
i = 1
x = 0
while (l[i-1]>=i)and(i<n):
	x += 1
	i += 1
if (l[n-1]>=n):
	x+=1
	i+=1	
f2.write(str(x)+'\n')
for y in range(i-1):
	f2.write(str(y+1) + ' ' + str(y+1)+'\n')
	
