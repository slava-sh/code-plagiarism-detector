import sys

L = int(input())
s = input()
c = 0
for i in ('a', 'b', 'c'):
            if i in s:
                c += 1
if c <= 2:
    good =""
    for i in range(1, min(L + 1, len(s))):
        if s[:i] * (len(s) // i) == s:
            good = s[:i]
            break
    if good != "":
        print(1)
        print(good)
    else:
        ans =[]
        for i in ('a', 'b', 'c'):
            if i in s:
                ans += [i]
        print(len(ans), '\n'.join(ans), sep = '\n')

else:
    if len(s) <= L:
        print(1, s, sep = '\n')
        sys.exit()
    good =""
    for i in range(1, min(L + 1, len(s))):
        if s[:i] * (len(s) // i) == s:
            good = s[:i]
            break
    if good != "":
        print(1)
        print(good)
        sys.exit()
    for i in range(0, (L * 7) // 2):
        for j in range((i * 3) // 2, (L * 7) // 2):
            for k in range(0, (L * 7) // 2):
                for l in range((k * 3) // 2, (L * 7) // 2):
                    m = s[i:j]
                    n = s[k:l]
                    #m, n = max(m, n), min(m, n)
                    s1 = s[:]
                    s1 = s1.replace(m, '#' * len(m))
                    s1 = s1.replace(n, '#' * len(n))
                    if s1 == '#' * len(s) and len(m) <= L and len(n) <= L:
                        print(2, m, n, sep = '\n')
                        sys.exit()
    print(3, 'a', 'b', 'c', sep = '\n')
            
