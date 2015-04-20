inp = open('che.in', 'r')
n, r = list(map(int, inp.readline().split()))
lis = list(map(int, inp.readline().split()))
s = 0
inp.close()
for i in range(len(lis)):
    h = lis[i]
    for j in range(i, len(lis)):
        if lis[j] > h + r:
            s += 1
print(s, file = open('che.out', 'w'))