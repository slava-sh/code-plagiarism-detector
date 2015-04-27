l = int(input())
s = input()

def f(s, arr):
    if len(s) == 0:
        return [True, arr]
    a = False
    for i in arr:
        if len(s) >= i[0]:
            a = True
    if a:
        for i in range(len(arr)):
            if arr[i][0] <= len(s):
                if arr[i][1] == 'd':
                    arr[i][1] = s[:arr[i][0]]
                    if f(s[arr[i][0]:], arr)[0]:
                        return [True, arr]
                    else:
                        arr[i][1] = 'd'
                else:
                    if arr[i][1] == s[:arr[i][0]]:
                        if f(s[arr[i][0]:], arr)[0]:
                            return [True, arr]
    return [False, arr]

for i in range(1, l + 1):
    x = f(s, [[i, 'd']])
    if x[0] == True:
        print(1)
        print(x[1][0][1])
        break
else:
    a = False
    for i in range(1, l + 1):
        if not(a):
            for j in range(1, l + 1):
                x = f(s, [[i, 'd'], [j, 'd']])
                if x[0]:
                    print(2)
                    print(x[1][0][1])
                    print(x[1][1][1])
                    a = True
                    break
    if not(a):
        print(3)
        print('a')
        print('b')
        print('c')
        
    