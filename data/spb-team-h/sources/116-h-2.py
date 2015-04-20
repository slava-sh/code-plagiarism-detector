fin = open('names.in')
n = int(fin.readline().strip())
people = dict()

for step in range(n):
    p = list(fin.readline().split())
    for i in range(2):
        name = p[i]
        if name in people.keys():
            people[name].append(p)
        else:
            people[name] = [p]
fin.close()

ans = list()
cur = 0
names = set()
for i in people.keys():
    if len(people[i]) > 1:
        people[i].sort()
        check = True
        for j in range(len(people[i]) - 1):
            if (people[i][j][0] == people[i][j + 1][0]) and (people[i][j][1] == people[i][j + 1][1]) and people[i][j][1] == i:
                check = False
                break
        if check:
            for j in range(len(people[i])):
                if people[i][j][0] == i:
                    #ans[cur] = people[i][j][2] + ' ' + people[i][j][0] + ' ' + people[i][j][1]
                    ans.append([people[i][j][2], people[i][j][0],  people[i][j][1]])
                    names.add(people[i][j][0])
                else:
                    #ans[cur] = people[i][j][0] + ' ' + people[i][j][1] + ' ' + people[i][j][2]
                    ans.append([people[i][j][0],  people[i][j][1], people[i][j][2]])
                    names.add(people[i][j][1])
                cur += 1

ans.sort()
fout = open('names.out', 'w')
for i in range(len(ans)):
    if not ans[i][0] in names:
        fout.write(' '.join(ans[i]) + '\n')
