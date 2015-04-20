from math import sqrt

def noder(a, b) :
    while (a != 0 and b != 0) :
        if (a > b) :
            a %= b
        else :
            b %= a
    if (a == 0) :
        return b
    else :
        return a

f = open("gcm.in")
l = f.read()
f.close()
s = l.split()
a = int(s[0])
b = int(s[1])

f = open("gcm.out", "w")


nod = noder(a, b)
nok = a * b / nod
c = int(sqrt(a * b))
index1 = 0
index2 = 0
if (c * c != a * b):
    index1 = 1
while (True) :
    if ((c + index1) == b or (c - index2) == a) :
        f.write(str(a)+' '+str(b))
        break
    if ((c + index1) * (c + index2) / nok == noder(c,c)):
        f.write(str(c + index1)+' '+str(c - index2))
        break
    index1 += 1
    index2 -= 1
f.close()

