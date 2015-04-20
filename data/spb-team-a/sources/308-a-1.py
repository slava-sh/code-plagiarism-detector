import sys
sys.stdin = open('abcd.in', 'r')
sys.stdout = open('abcd.out', 'w')
n = int(input())
for a in range(n):
    string = input()
    if (int(string[:2]) ** 2 + int(string[2:]) ** 2) % 7 == 1:
        print('YES')
    else:
        print('NO')