f = open('names.in','rt')
f2 = open('names.out','wt')
n = f.readline().split()
n = int(n[0]) 
s = [[] for i in range(n)]
isr = [False for i in range(n)]   
for i in range(n):
	c = f.readline().split()
	(s[i]).append(c[0])
	(s[i]).append(c[1])
	(s[i]).append(c[2])                                  
	
for k in range(n):
	if isr[k]==False:
		for i in range(2):
			#print(k , i)
			if isr[k]==False:
				for j in range(n):
					if j != k:
						for i2 in range(2):
							if s[k][i]==s[j][i2]:
								isr[k], isr[j] = True, True
								if (i==0) : s[k][0],s[k][1],s[k][2] = s[k][2],s[k][0],s[k][1]
								if (i2==0): s[j][0],s[j][1],s[j][2] = s[j][2],s[j][0],s[j][1]
								#print(s[k][0] + ' ' + s[k][1] + ' ' + s[k][2] + '\n')
								#print(s[j][0] + ' ' + s[j][1] + ' ' + s[j][2] + '\n')

							
def newsort(s):
	l = []
	for i in range(len(s)): l.append(s[i][0]+' '+str(i))
	l.sort()
	l2 = []
	for i in range(len(l)): l2.append(int((l[i].split())[1]))
	l3 = []
	for i in range(len(s)): l3.append(s[l2[i]])
	return l3 
		
s = newsort(s)	
            
for i in range(n):
	f2.write(s[i][0] + ' ' + s[i][1] + ' ' + s[i][2] + '\n')
