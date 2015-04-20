f = open("abcd.in", "r")

a = int(f.readline())
b = 0

c = [0] * (a + 1)

for i in range(a):
    b = str(f.readline())

    a1 = (ord(b[0]) - 48) * 10
    a1 += ord(b[1]) - 48

    a2 = (ord(b[2]) - 48) * 10
    a2 += ord(b[3]) - 48
    if (a1 * a1 + a2 * a2) % 7 == 1:
        c[i] = 'YES'
    else:
        c[i] = 'NO'

f = open("abcd.out", "w")

for i in range(a):
    f.write(c[i] + "\n")