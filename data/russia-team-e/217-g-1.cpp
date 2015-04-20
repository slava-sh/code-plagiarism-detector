#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n,m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 1) {
        int d = (n+m-1) / 4;
        if ((n+m-1) % 4 == 3) d++;
        printf("%d", d);
        return 0;
    }
    if (n == 2 || m == 2) {
        printf("0");
        return 0;
    }
    printf("1");
    return 0;
}
