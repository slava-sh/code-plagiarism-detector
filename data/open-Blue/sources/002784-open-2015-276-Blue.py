n = int(input())
string = input()
s = set(list(string))
if n >= len(string):
    print(string)
else:
    print(len(s))
    for i in s:
        print(i)
