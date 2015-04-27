def check(mes, s):
    if len(mes) % len(s) != 0:
        return 0
    while s == mes[:len(s)]:
        mes = mes[len(s):]
    if len(mes) != 0:
        return 0
    return 1


def check2(mes, w1, w2):
    lw1 = len(w1)
    lw2 = len(w2)
    d = [0 for i in range(len(mes))]
    for i in range(len(mes)):
        if i == lw1 and mes[:lw1] == w1:
            d[i-1] = 1
            continue
        if i == lw2 and mes[:lw2] == w2:
            d[i-1] = 1
            continue
        if i >= lw1 and mes[i-lw1+1:i+1] == w1 and d[i- lw1] == 1:
            d[i] = 1
            continue
        if i >= lw2 and mes[i-lw2+1:i+1] == w2 and d[i- lw2] == 1:
            d[i] = 1
            continue
    if d[-1] == 1:
        return 1


def main():
    l = int(input())
    mes = input().rstrip()
    #1 word
    for i in range(1, min(len(mes), l) + 1):
        pref = mes[:i]
        if check(mes, pref):
            print(1)
            print(pref)
            return
    #2 word
    for i in range(1, min(len(mes), l) + 1):
        if len(mes) - i > 0:
            mes_ = mes[i:]
            w1 = mes[:i]
            for j in range(1, min(len(mes_), l) + 1):
                for q in range(len(mes_) - j):
                    if j + q < len(mes_) and q >= 0:
                        if check2(mes, w1, mes_[q:q+j]):
                            print(2)
                            print(w1)
                            print(mes_[q:q+j])
                            return
    #3
    lets = []
    for i in range(len(mes)):
        if mes[i] not in lets:
            lets.append(mes[i])
    print(len(lets))
    for elem in lets:
        print(elem)
main()