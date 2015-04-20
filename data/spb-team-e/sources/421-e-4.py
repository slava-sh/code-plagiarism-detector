fin = open("game.in", 'r')
fout = open("game.out", 'w')

n, m = list(map(int, fin.readline().strip().split(' ')))
l1, r1 = list(map(int, fin.readline().strip().split(' ')))
l2, r2 = list(map(int, fin.readline().strip().split(' ')))

p1, p2, o = 0, 0, 0
#for i in range(n):
    #l = int(fin.readline().strip())
    #if (((l1 <= l) and (l <= r1)) and ((l2 <= l) and (l <= r2))):
	#o += 1
    #if ((l1 <= l) and (l <= r1)):
	#p1 += 1
    #if ((l2 <= l) and (l <= r2)):
	#p2 += 1
l_list = list(map(int, fin.readline().strip().split(' ')))
for l in l_list:
    if ((l1 <= l) and (l <= r1)):
        if ((l2 <= l) and (l <= r2)):
            o = o + 1
    if ((l1 <= l) and (l <= r1)):
        p1 += 1
    if ((l2 <= l) and (l <= r2)):
        p2 += 1

r1, r2 = 0, 0
i = 1
while ((m > 0) and ((p1 > 0) or (p2 > 0))):
    if (i % 2 == 1): #p1
        if o > 0:
            r1 += 1
	    
            o -= 1
            p1 -= 1
            p2 -= 1
            m -= 1
        elif p1 > 0:
            r1 += 1
            p1 -= 1
            m -= 1
    else:
        if o > 0:
            r2 += 1
            o -= 1
            p1 -= 1
            p2 -= 1
            m -= 1
        elif p2 > 0:
            r2 += 1
            p2 -= 1
            m -= 1
    i += 1

if r1 > r2:
    fout.write("Petya")
elif r2 > r1:
    fout.write("Vasya")
else: fout.write("Draw")    
fin.close()
fout.close()