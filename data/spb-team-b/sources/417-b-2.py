f = open("chess.in", "r")

a = int(f.readline())
b = [int(i) for i in f.readline().split()]

x, y, i, s = 1, 1, 0, 0

flag = False

lx = [0] * 1000
ly = [0] * 1000

while x < a:
    while b[x - 1] < y:
        x += 1
        if x > a:
            flag = True
            break
    if flag: break
    lx[s] = x
    ly[s] = y
    s += 1
    y += 1
    x += 1

f = open("chess.out", "w")

f.write(str(s) + "\n")

for i in range(s):
    f.write(str(lx[i]) + ' ' + str(ly[i]) + "\n" )



