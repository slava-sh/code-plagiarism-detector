from sys import setrecursionlimit
import threading


def main():
    fin = open('dunes.in')
    fout = open('dunes.out', 'w')
    n, m = map(int, fin.readline().split())
    l = []
    r = []
    x = []
    q = []
    for i in range(n):
        li, ri, xi = map(int, fin.readline().split())
        l.append(li - 1)
        r.append(ri)
        x.append(xi)
    for i in range(m):
        j = int(fin.readline())
        q.append(j)
    mini = min(l)
    for i in q:
        el = 0
        for j in range(n):
            if (l[j] <= i - 1 < r[j]):
                if (i - 1 - l[j]) % 2 == 0:
                    el += x[j]
                else:
                    el -= x[j]
        print(el, file = fout)
    fin.close()
    fout.close()
    
    
thread = threading.Thread(target = main)
thread.start()