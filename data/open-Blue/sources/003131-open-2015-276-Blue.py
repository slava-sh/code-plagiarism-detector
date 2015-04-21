n = int(input())
string = input()
s = set(list(string))
for i in range(len(string)//2+len(string)%2, n+1):
    if string[:i] == string[len(string)-i:]:
        print(1)
        print(string[:i])
        exit()
print(len(s))
for i in s:
    print(i)
