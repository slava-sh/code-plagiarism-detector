f = open("merlin.in", "r")

N = int(f.readline())

m = [int(i) for i in f.readline().split()]

m.sort()

sumall = sum(m)
k = 0

while sumall < (N - k) * m[N - k - 1]: k += 1


f = open("merlin.out", "w")
f.write(str(k))



