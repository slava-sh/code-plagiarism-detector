file_in = open("chess.in", "r")
file_out = open("chess.out", "w")

n = int(file_in.readline())

arr = list(map(int, file_in.readline().split()))

mas = [[0 for i in range(1000)] for i in range(1000)]

for i in range(n):
    for j in range(arr[i]):
        mas[i][j] = 1
cnt = 0
for i in range(n):
    if (mas[i][i] == 1):
        cnt += 1
    else:
        break
print(cnt, file = file_out)

for i in range(cnt):
    print(i + 1, i + 1, file = file_out)
