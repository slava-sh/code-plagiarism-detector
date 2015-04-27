hl, hr, n = map(int, raw_input().split())
mir = [[], []]
for i in xrange(n):
    line = raw_input().split()
    pnt, l, r = int(line[0]), int(line[2]), int(line[3])
    t = 0 if line[1] == 'F' else 1
    mir[t].append((l, r, pnt, i))
ans = 0
eps = 1.e-7
for q in xrange(2):
    H = [hr]
    for i in xrange(n):
        mir_ = -i * 100
        h = mir_ * 2 - H[-1]
        H.append(h)
        ref = set()
        can = 1
        pnt = 0
        for j in xrange(i+1):
            a = j % 2
            pos = 100000.0 * (hl + 100 * j) / (hl - h)
            for m in mir[a]:
                if m[0] - eps < pos < m[1] + eps:
                    if m[3] in ref:
                        can = 0
                        break
                    ref.add(m[3])
                    pnt += m[2]
            if len(ref) < j + 1: can = 0
            a = 1 - a
            if not can: break
        if can:
            ans = max(ans, pnt)
        #print q, ref, can, i, pnt
    mir[1], mir[0] = mir[0], mir[1]
    hl, hr = 100 - hl, 100 - hr
print ans 
