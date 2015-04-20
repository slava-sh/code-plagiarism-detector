from sys import setrecursionlimit
import threading


def main():
    fin = open('gcm.in')
    fout = open('gcm.out', 'w')
    n, m = map(int, fin.readline().split())
    n1, m1 = n, m
    shtukovina = 0
    while (m1 * n1 > 0):
        m1 = m1 % n1
        m1, n1 = n1, m1
    if n1 == 0:
        shtukovina = m1
    else:
        shtukovina = n1
    md = shtukovina
    x = n * m
    div = []
    summ = 10000000
    need1 = 1
    d = 1
    need2 = x
    x //= md * md
    divs = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            divs.append(i)
        i += 1
    for d in divs:
        if (x % d == 0) and (abs(x // d - d) < summ):
            n1, m1 = x // d, d
            shtukovina = 0
            while (m1 * n1 > 0):
                m1 = m1 % n1
                m1, n1 = n1, m1
            if n1 == 0:
                shtukovina = m1
            else:
                shtukovina = n1   
            if shtukovina == 1:
                summ = abs(x // d - d)
                need1 = d
                need2 = x // d
    print(need1 * md, need2 * md, file = fout)
    fin.close()
    fout.close()


thread = threading.Thread(target = main)
thread.start()
