flag = False
l = int(input())
S = raw_input()
for i in range(1, min(l, len(S)) + 1):
    word = S[:i]
    if (len(S) % len(word) == 0):
        for j in range(len(word), len(S), len(word)):
            if (word != S[j:j + len(word)]):
                break
        else:
            if not flag:
                flag = True
                print 1
                print word
if not flag:
    print 2
    print 'a'
    print 'b'
