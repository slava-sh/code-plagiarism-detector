f = open("names.in", "r")

N = int(f.readline())

names = [[''] * 3] * N

for i in range(N):
    names[i] = [str(i2) for i2 in f.readline().split()]

names2_1 = [''] * N
names2_2 = [''] * N
names2_3 = [''] * N

mnogo = [''] * ((N + 1) * 3)

for i in range(N):
    for i2 in range(3):
        mnogo[i * 3 + i2] = names[i][i2]

for i in range(N):
    if mnogo.count(names[i][0]) > 1:
        names2_1[i] = names[i][2]
        names2_2[i] = names[i][0]
        names2_3[i] = names[i][1]
    else:
        names2_1[i] = names[i][0]
        names2_2[i] = names[i][1]
        names2_3[i] = names[i][2]

names3 = [''] * N

for i in range(N):
    names3[i] = names2_1[i]

for i in range(N):
    if len(names2_1[i]) < 20:
        for i2 in range(20 - len(names2_1[i])): names3[i] += 'a'

mas = [0] * N

for i in range(N):
    mas[i] += (ord(names3[i][0]) - ord('A')) * (26 ** 20)
    for i2 in range(1, 20):
        mas[i] += (ord(names3[i][i2]) - ord('a')) * (26 ** (20 - i2))

mas2 = [0] * N
for i in range(N): mas2[i] = mas[i]

mas.sort()

f = open("names.out", "w")

for i in range(N):
    for i2 in range(N):
        if mas[i] == mas2[i2]:
           f.write(names2_1[i2] + ' ' + names2_2[i2] + ' ' + names2_3[i2] + "\n")






