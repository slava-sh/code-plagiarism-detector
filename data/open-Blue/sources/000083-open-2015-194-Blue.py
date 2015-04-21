l = int(input())
s = input()
x = set(list(s))
if len(x) == 1:
    print(len(x))
    for i in x:
        print(i)
elif len(x) == 2:
    if len(s) <= l:
        print(1)
        print(s)
    else:
        print(len(x))
        for i in x:
            print(i)
else:
    if len(s) <= l:
        print(1)
        print(s)
    elif len(s) <= l * 2:
        print(2)
        print(s[:l])
        print(s[l:])
    else:
        print(len(x))
        for i in x:
            print(i)