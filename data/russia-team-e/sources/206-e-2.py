import sys
sys.stdin = open("numbers.in")
sys.stdout = open("numbers.out", "w")


class Country :
    def __init__(self):
        code, k = tuple(map(int, input().split()))
        self.code = str(code)
        self.ops = []
        for i in range(k):
            self.ops.append(input())
#            print("%s appended" % (self.ops[-1]))
    def fit(self, number):
        for op in self.ops:
#            print("Is %s starts with %s?" % (number, self.code + op))
            if (number.startswith(self.code + op) and
                number[len(self.code + op)] != "0"):
                return "+%s(%s)" % (self.code, op)
        return None

def parse(number):
    if len(number) == 3:
        return number
    if len(number) == 4:
        return number[:2] + "-" + number[2:]
    if len(number) == 5:
        return number[:3] + "-" + number[3:]
    if len(number) == 6:
        return number[:2] + "-" + number[2:4] + "-" + number[4:]
    if len(number) == 7:
        return number[:3] + "-" + number[3:5] + "-" + number[5:]

def main():
    n = int(input())
    countries = []
    for i in range(n):
       countries.append(Country())
    m = int(input())
    for i in range(m):
        number = input()
        ok = False
        for cntr in countries:
            if number.startswith(cntr.code):
                prefix = cntr.fit(number)
                if prefix is not None:
                    print(prefix + parse(number[len(prefix) - 3:]))
                    ok = True
                    break
        if not ok:
            print("Incorrect")

main()

sys.stdin.close()
sys.stdout.close()
