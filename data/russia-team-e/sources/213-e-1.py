from sys import *
in_file = open("numbers.in", 'r');
out_file = open("numbers.out", 'w');
n = int(in_file.readline())
c = []
k = []
for i in range(n):
    q, w = in_file.readline().split()
    c.append(q)
    tmp = []
    w = int(w)
    for i in range(w):
        d = in_file.readline().strip()
        tmp.append(d)
    k.append(tmp)
m = int(in_file.readline())

def makem(s):
    if len(s) == 3:
        return s
    if(len(s) == 4):
        return s[:2]+"-"+s[2:]
    if(len(s) == 5):
        return s[:3]+"-"+s[3:]        
    if(len(s) == 6):
        return s[:2]+"-"+s[2:4]+ "-" + s[4:]  
    if(len(s) == 7):
            return s[:3]+"-"+s[3:5]+ "-" + s[5:]     
numbers = []
for i in range(m):
    res = ""
    s = in_file.readline().strip()
    countr = -1
    for j in range(len(c)):
        if s.find(c[j]) == 0:
            countr = j
    if countr == -1:
        print("Incorrect", file = out_file)
        continue
    res += "+" + str(c[countr])
    region = -1
    for j in range(len(k[countr])):
        if s.find(k[countr][j]) == len(c[countr]) and s[len(c[countr]) + len(k[countr][j])] != '0':
            #print(k[countr][j])
            #print(s[len(c[countr]) + len(k[countr][j])])
            region = j
    if region == -1:
        print("Incorrect", file = out_file)
        continue
    res += "(" + str(k[countr][region]) + ")"
    tmp = s[len(k[countr][region]) + len(c[countr]):]
    if tmp[0] == '0':
        print("Incorrect", file = out_file)
        continue 
    res += makem(tmp)
    print(res, file = out_file)
out_file.close()
            
        