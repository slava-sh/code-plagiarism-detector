infile = open('chess.in')
outfile = open('chess.out', 'w')
n = int (infile.readline())
a = list(map (int, infile.readline().split()))
ans = []
for i in range(n):
    if i < a[i]:
        ans.append([i + 1, i + 1])
    else:
        break
print(len(ans), file = outfile)
for i in ans:
    print(*i, file = outfile)