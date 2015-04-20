n = int(input().strip())
g = {}
for i in range(n):
    c, k = input().split()
    g[c] = []
    for i in range(int(k)):
        g[c].append(input().strip())
m = int(input().strip())
answ = []
for i in range(m):
    no = input().strip()
    b = True
    st = False
    if no[0] in g:
        for j in g[no[0]]:
            if no[1:len(j) + 1] == j:
                st = True
                answ.append('+' + no[0] + '(' + j + ')' + ''.join(no[len(j) + 1:]))
    elif no[:2] in g:
        for j in g[no[:2]]:
            if no[2:2 + len(j)] == j:
                st = True
                answ.append('+' + no[:2] + '(' + j + ')' + ''.join(no[len(j) + 2:]))
    elif no[:3] in g:
        for j in g[no[:3]]:
            if no[3:3 + len(j)] == j:
                st = True
                answ.append('+' + no[:3] + '(' + j + ')' + ''.join(no[len(j) + 3:]))
    if st == False:
        answ.append('Incorrect')
                
for i in answ:
    if i == 'Incorrect':
        print(i)
    else:
        u = i.index(')')
        if i[u + 1] == '0':
            print('Incorrect')
        elif 13 - u == 3:
            print(i)
        elif 13 - u == 4:
            print(i[:u + 1] + i[u + 1:u + 3] + '-' + i[u + 3:])
        elif 13 - u == 5:
            print(i[:u + 1] + i[u + 1:u + 4] + '-' + i[u + 4:])
        elif 13 - u - 2 == 6:
            print(i[:u + 1] + i[u + 1:u + 3] + '-' + i[u + 3:u + 5] + '-' + i[u + 5:])
        elif 13 - u == 7:
            print(i[:u + 1] + i[u + 1:u + 4] + '-' + i[u + 4:u + 6] + '-' + i[u + 6:])   
