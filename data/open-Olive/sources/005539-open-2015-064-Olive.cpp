#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 5555;

int s[maxn][maxn], h[maxn], n;

int sign(int x) {
    return (x == 0 ? 0 : x > 0 ? 1 : -1);
}

int getSum(int x, int xx, int y, int yy) {
    return s[xx][yy] - s[x - 1][yy] - s[xx][y - 1] + s[x - 1][y - 1];
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    n = nextInt<int>();

    for (int i = 1; i <= n; i++) {
        h[i] = nextInt<int>();
        s[i][h[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];

    int best = -1, x = -1, y = -1;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (h[i] > h[j]) {
                if (abs(i - j) == 1) {
                    if (1 > best) {
                        best = 1;
                        x = i, y = j;
                    }
                }
                else {
                    int t = getSum(i + 1, j - 1, h[j], h[i]);
                    if (t > best) {
                        best = t;
                        x = i, y = j;
                    }
                }
            }
        }

    printf("%d %d\n", x, y);

    return 0;
}
