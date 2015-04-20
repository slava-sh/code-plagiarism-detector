from sys import *
in_file = open("numbers.in", 'r');
out_file = open("numbers.out", 'w');
n = int(in_file.readline())
c = []
k = []
for i in range(n):
    q, w = in_file.readline().split()
    q = q.strip()
    c.append(q)
    tmp = []
    w = int(w)
    for j in range(w):
        d = in_file.readline().strip()
        if d == '':
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
    return 1 / 0
numbers = []
for i in range(m):
    res = ""
    s = in_file.readline().strip()
    if s == '':
        s = in_file.readline().strip()
    countr = -1
    ok = False
    for country_num in range(len(c)):
        if c[country_num][0] == '0':
            break;
        if s.find(c[country_num]) == 0:
            for region_num in range(len(k[country_num])):
                if k[country_num][region_num][0] == '0':
                    break;                
                if s.find(k[country_num][region_num]) == len(c[country_num]) and s[len(c[country_num]) + len(k[country_num][region_num])] != '0':
                    tmp = s[len(c[country_num]) + len(k[country_num][region_num]):]
                    print("+" + c[country_num] + "(" + k[country_num][region_num] + ")" + makem(tmp), file = out_file)
                    ok = True
                    break
        if ok:
            break;
    if not ok:
        print("Incorrect", file = out_file)
out_file.close()
            
        