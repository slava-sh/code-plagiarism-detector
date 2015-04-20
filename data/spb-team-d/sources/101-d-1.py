infile = open('dunes.in')
outfile = open('dunes.out', 'w')
n, m = map(int, infile.readline().split())
nums = []
for i in range(n):
    nums.append(list(map(int, infile.readline().split())))
for i in range(m):
    a = int(infile.readline())
    s = 0
    for j in nums:
        if a <= j[1] and a >= j[0]:
            if (a - j[0]) & 1 == 0:
                s += j[2]
            else:
                s -= j[2]
        
    print(s, file = outfile)