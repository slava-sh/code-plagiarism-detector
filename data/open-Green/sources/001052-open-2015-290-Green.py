#!/usr/bin/python3


def solve(n, k):
    if k == 1:
        return (n + 1) // 2
    i = 2
    while i * i <= n:
        if n % i == 0:
            return solve(n // i, k - 1) * ((i + 1) // 2)
        i += 1
    return solve(n, k - 1)


n, k = map(int, input().split())
print(solve(n, k))
