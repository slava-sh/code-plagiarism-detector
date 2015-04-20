fin = open("merlin.in", 'r')
fout = open("merlin.out", 'w')

n = int(fin.readline().strip())
a = list(map(int, fin.readline().strip().split(' ')))
a.sort()

h = [0]
for i in range(1, n):
    h.append(h[i - 1] + (a[i] - a[i - 1]) * i)

s = [0 for i in range(n)]
s[-1] = a[-1]
for i in range(-1, -n, -1):
    s[i] = s[i + 1] + a[i]

s.append(0)
k = n - 1
while h[k] > s[k + 1]:
    k -= 1
    
fout.write(str(n - k - 1))

fin.close()
fout.close()