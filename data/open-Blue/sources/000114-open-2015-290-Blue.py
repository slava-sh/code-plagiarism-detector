#!/usr/bin/python3

def is_cyclear(s, l):
    if len(s) % l:
        return False
    for i in range(0, len(s) - l + 1, l):
        if s[i:i + l] != s[:l]:
            return False
    return True


l = int(input())
s = input()

for i in range(1, min(l + 1, len(s))):
    if is_cyclear(s, i):
        print(1)
        print(s[:l])
        exit(0)

if 'a' in s and 'b' in s:
    print(2)
    print('a')
    print('b')
else:
    print(1)
    print(s[0])
