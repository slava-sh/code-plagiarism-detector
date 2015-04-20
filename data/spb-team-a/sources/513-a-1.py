file_in = open("abcd.in", "r")
file_out = open("abcd.out", "w")

n = int(file_in.readline())
for i in range(n):
    string = file_in.readline().rstrip()
    if ((int(string[0:2]) ** 2 + int(string[2:4]) ** 2) % 7 == 1):
        print("YES", file = file_out)
    else:
        print("NO", file = file_out)

file_in.close()
file_out.close()