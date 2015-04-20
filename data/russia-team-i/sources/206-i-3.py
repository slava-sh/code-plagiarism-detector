import sys
sys.stdin = open("sochi.in")
sys.stdout = open("sochi.out", "w")

n, d = tuple(map(int, input().split()))
a = list(map(int, input().split()))
mx = max(a)

edge = []
middle = []
another = []

for i in a:
    if i >= 3 * d:
        middle.append(i)
    elif i > d:
        edge.append(i)
    else:
        another.append(i)

ans = 0
if edge == [] and middle == []:
    ans = max(another)
else:
    count = 0
    summa = 0
    for i in middle:
        summa += i
        count += 1
    edge.sort()
    if len(edge) >= 2:
        summa += edge[-1] + edge[-2]
        count += 2
    if len(edge) == 1:
        summa += edge[0]
        count += 1
    if count >= 2:
        summa -= 2 * d + (count - 2) * 2 * d
    ans = summa
#    print(count)

print(max(mx, ans))

sys.stdin.close()
sys.stdout.close()
        
