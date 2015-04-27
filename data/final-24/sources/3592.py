n = int(input())
s = input()
ans = False

for i in range(1, n + 1):
    if len(s) % i == 0 and s[:i] * (len(s) // i) == s:
        print(1)
        print(s[:i])
        ans = True
        break

if ans == False:
    print(2)
    print('a')
    print('b')