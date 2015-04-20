fi, fo = open("numbers.in", "r"), open("numbers.out", "w+")
#fi, fo = open("input.txt", "r"), open("output.txt", "w+")
n = int(fi.readline())
gos = []
reg = [[]]
for i in range(n):
    c, k = (map(int, fi.readline().split()))
    gos.append(c)
    reg.append([])
    for j in range(k):
        r = int(fi.readline())
        reg[i].append(r)

m = int(fi.readline())
for i in range(m):
    resR, resG, res = "", "", ""
    s = fi.readline()
    if s[-1:] != "\n": s += "\n"
    if len(s) != 12:
        fo.write("Incorrect\n")
        continue
    for j in range(1, 4):
        sG = int(s[0:j])
        if sG not in gos: continue
        sGi = gos.index(sG)
        for k in range(3, 6):
            sR = int(s[j:j+k])
            if sR not in reg[sGi]: continue
            if s[j+k] == "0": continue
            resG , resR = str(sG), str(sR)
    if resG == "":
        fo.write("Incorrect\n")
        continue
    res = "+" + resG + "(" + resR + ")"
    l = len(s) - len(resG) - len(resR) - 1
    if l == 3: res += s[8:11]
    if l == 4: res += s[7:9] + "-" + s[9:11]
    if l == 5: res += s[6:9] + "-" + s[9:11]
    if l == 6: res += s[5:7] + "-" + s[7:9] + "-" + s[9:11]
    if l == 7: res += s[4:7] + "-" + s[7:9] + "-" + s[9:11]
    fo.write(res+"\n")
fi.close()
fo.close()