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
    md = 1
    summ = 10000000
    need1 = 1
    d = 1
    need2 = x
    while d * d <= x:
        if (x % d == 0) and (abs(x // d - d) < summ):
            n1, m1 = d, x // d
            shtukovina = 0
            while (m1 * n1 > 0):
                m1 = m1 % n1
                m1, n1 = n1, m1
            if n1 == 0:
                shtukovina = m1
            else:
                shtukovina = n1   
            if shtukovina == md:
                summ = abs(x // d - d)
                need1 = d
                need2 = x // d
        d += 1
    print(need1, need2, file = fout)
    fin.close()
    fout.close()


thread = threading.Thread(target = main)
thread.start()
