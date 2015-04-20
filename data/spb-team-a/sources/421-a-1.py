fin = open("abcd.in", 'r')
fout = open("abcd.out", 'w')

n = int(fin.readline().strip())

for i in range(n):
    inp = fin.readline().strip()
    a = 10 * int(inp[0]) + int(inp[1])
    b = 10 * int(inp[2]) + int(inp[3])
    
    if (a**2 + b**2) % 7 == 1:
        fout.write('YES\n')
    else:
        fout.write("NO\n")


fin.close()
fout.close()