fin = open('names.in')
n = int(fin.readline().strip())
people = dict()
ans = [''] * n
cur = 0

for step in range(n):
    p = list(fin.readline().split())
    for i in range(2):
        name = p[i]
        if name in people.keys():
            if people[name][1]:
                ans[cur] = people[name][0]
                people[name][1] = False
                cur += 1
            if not i:
                ans[cur] = p[2] + ' ' + p[0] + ' ' + p[1]
            else:
                ans[cur] = p[0] + ' ' + p[1] + ' ' + p[2]
            cur += 1
        else:
            if not i:
                people[name] = [p[2] + ' ' + p[0] + ' ' + p[1], True]
            else:
                people[name] = [p[0] + ' ' + p[1] + ' ' + p[2], True]

ans.sort()
fout = open('names.out', 'w')
fout.write('\n'.join(ans))