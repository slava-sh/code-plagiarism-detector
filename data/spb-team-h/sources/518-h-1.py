fin = open("names.in")
fout = open("names.out", "w")
n = int(fin.readline())
people = []
names = {}
for i in range(n):
    a = fin.readline().split()
    if a[0] in names.keys():
        names[a[0]] += 1
    else:
        names[a[0]] = 1

    if a[1] in names.keys():
        names[a[1]] += 1
    else:
        names[a[1]] = 1
    people.append(a)
ans = []

for person in people:
    if names[person[0]] >= 2:
        ans.append( [person[2], person[0], person[1]])
    else:
        ans.append( person)
for person in sorted(ans, key=lambda x: x[0]):
    fout.write(' '.join(person)+'\n')
fout.close()