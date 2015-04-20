import sys
sys.stdin = open("numbers.in")
sys.stdout = open("numbers.out", "w")

n = int(input())
d = {}
for i in range(n):
    code, k = input().split()
    k = int(k)
    for j in range(k):
        gor = input()
        d[code + gor] = "+{}({})".format(code, gor)
        
        
def fmt(s):
    if len(s) == 3:
        return s
    if len(s) == 4:
        return '{}-{}'.format(s[:2], s[2:])
    if len(s) == 5:
        return '{}-{}'.format(s[:3], s[3:])
    if len(s) == 6:
        return '{}-{}-{}'.format(s[:2], s[2:4], s[4:])
    if len(s) == 7:
        return '{}-{}-{}'.format(s[:3], s[3:5], s[5:])
    
    
m = int(input())
for i in range(m):
    number = input()
    for j in range(1, 9):
        if number[j] != '0' and number[:j] in d:
            print(d[number[:j]] + fmt(number[j:]))
            break
    else:
        print("Incorrect")
