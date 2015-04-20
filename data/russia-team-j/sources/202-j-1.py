import sys
sys.stdin = open('travel.in')
sys.stdout = open('travel.out', 'w')


w, h, n = map(int, input().split())
m = [input() for i in range(h)]
v = next((line.index('V'), i) for i, line in enumerate(m) if 'V' in line)
from collections import deque
dist = [[None] * w for i in range(h)]
dist[v[1]][v[0]] = '', n

inf = 2 ** 64

def neigs(x, y):
    for dx, dy, l in (-1, 0, 'W'), (1, 0, 'E'), (0, 1, 'S'), (0, -1, 'N'):
        if 0 <= x + dx < w and 0 <= y + dy < h:
            yield x + dx, y + dy, l

pair = lone = None
def work_T(x, y):
    global pair, lone
    for nx, ny, l in neigs(x, y):
        if m[ny][nx] == 'T':
            # Wow, pair
            if pair is None:
                pair = x, y, l
            break
    else:
        if lone is None:
            lone = x, y, l

d = deque()
d.append(v)
while d:
    x, y = d.popleft()
    if m[y][x] == 'T':
        work_T(x, y)
    for nx, ny, l in neigs(x, y):
        if dist[ny][nx] is None:
            if m[ny][nx] == 'T':
                dist[ny][nx] = dist[y][x][0] + l, dist[y][x][1] - 1
                d.appendleft((nx, ny))
            else:
                dist[ny][nx] = dist[y][x][0] + l, dist[y][x][1]
                d.append((nx, ny))
                

dst_pair = dist[pair[1]][pair[0]] if pair is not None else None
dst_lone = dist[lone[1]][lone[0]] if lone is not None else None
res_pair = (len(dst_pair[0]) + dst_pair[1]) if pair is not None else inf
res_lone = (len(dst_lone[0])
            + 2 * dst_lone[1]) if lone is not None else inf
anti = {'N': 'S', 'S': 'N', 'W': 'E', 'E': 'W'}
if res_pair is not None and res_pair < res_lone:
    print(dst_pair[0] + ((pair[2]+anti[pair[2]]) * dst_pair[1])[:dst_pair[1]])
else:
    print(dst_lone[0] + (lone[2]+anti[lone[2]]) * dst_lone[1])
#print(res_pair, res_lone)