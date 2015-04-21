n = int(input())
string = input()
s = set(list(string))
if n >= len(string):
    print(1)
    print(string)
else:
    print(len(s))
    for i in s:
        print(i)
