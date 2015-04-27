#!/usr/bin/python3
def find_word():
    i = 1
    while True:
        if len(s) % i == 0 and s[:-i] == s[i:]:
            break
        i += 1
    return i


l = int(input())
s = input()
let = sorted(list(set(list(s))))
if len(let) == 1:
    print(1)
    print(s[0])
    exit(0)
if len(let) == 2:
    w = find_word()
    if w <= l:
        print(1)
        print(s[:w])
        exit(0)
    print(2)
    print(*let)
    exit(0)
print(3)
print(*let)
