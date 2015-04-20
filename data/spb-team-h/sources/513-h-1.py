file_in = open("names.in", "r")
file_out = open("names.out", "w")

n = int(file_in.readline())

st = set()
names = set()
strings = []

for i in range(n):
    strings.append(file_in.readline().split())
    for j in range(3):
        if (not strings[i][j] in st):
            st.add(strings[i][j])
        else:
            names.add(strings[i][j])

for i in range(n):
    if (strings[i][0] in names):
        strings[i][0], strings[i][1], strings[i][2] = strings[i][2], strings[i][0], strings[i][1]
        
strings.sort()

for i in range(n):
    for j in range(3):
        print(strings[i][j], file = file_out, end = " ")
    print(file = file_out)
