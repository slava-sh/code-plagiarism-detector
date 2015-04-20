inp = open('sochi.in', 'r')
out = open('sochi.out', 'w')
n, d = list(map(int, inp.readline().split()))
lis = list(map(int, inp.readline().split()))
lis1 = [i for i in lis if i > 2 * d]
lis2 = [i for i in lis if i > d and i <= 2 * d]
inp.close()
if len(lis1) != 0:
    if len(lis2) == 0:
        print(sum(lis1)  - d * 2 * (len(lis1) - 1), file = out)
    elif len(lis2) == 1:
        print(sum(lis1)  - d * 2 * (len(lis1) - 1) - d + lis2[0] - d, file = out)
    elif len(lis2) >= 2:
        lis2.sort(reverse = True)
        print(sum(lis1)  - d * 2 * (len(lis1) - 1) - 2 * d + lis2[0] + lis2[1] - 2 * d, file = out)
else:
    print(max(lis), file = out)
out.close()