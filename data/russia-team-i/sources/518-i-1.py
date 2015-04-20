def main():
    fin = open("sochi.in", "r")
    fout = open("sochi.out", "w")
    
    n, d = map(int, fin.readline().split())
    A = list(map(int, fin.readline().split()))
    
    mx1 = -1
    mx2 = -1
    sm = 0
    cnt = 0
    for elem in A:
        if elem <= d:
            pass
        elif elem >= 3 * d:
            sm += elem
            cnt += 1
        else:
            if elem > mx1:
                mx2 = mx1
                mx1 = elem
            elif elem > mx2:
                mx2 = elem
    
    if mx1 > -1:
        sm += mx1
        cnt += 1
    if mx2 > -1:
        sm += mx2
        cnt += 1
    
    fout.write(str(sm - 2 * (cnt - 1) * d))
    
    fin.close()
    fout.close()
    
main()