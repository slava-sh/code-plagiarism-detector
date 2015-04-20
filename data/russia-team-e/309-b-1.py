inp = open('che.in')
outp = open('che.out', 'w')

n, r = tuple(map(int, inp.readline().split()))
d = tuple(map(int, inp.readline().split()))

max_el = 0
res = 0
flag = False
for num, val in enumerate(d):
    try:
        while d[max_el] - val <= r:
            max_el += 1
            if max_el >= n:
                flag = True
                break
        if flag:
            break
    except IndexError:
        print(str(max_el) + ' ' + str(num) + ' ' + str(len(d)))
    res += n - max_el


outp.write(str(res))
inp.close()
outp.close()
