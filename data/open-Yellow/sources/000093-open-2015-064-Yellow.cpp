#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
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

const int INF = (int)1e9 + 5;

const int maxn = 100500;

int N, Q;
int t[maxn];
int res;

void change(int i, int val) {
    if (t[i] != t[i - 1]) res--;
    if (i + 1 <= N && t[i + 1] != t[i]) res--;
    t[i] = val;
    if (t[i] != t[i - 1]) res++;
    if (i + 1 <= N && t[i + 1] != t[i]) res++;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    N = nextInt<int>();

    for (int i = 1; i <= N; i++)
        t[i] = nextInt<int>();

    t[0] = -INF;

    for (int i = 1; i <= N; i++)
        if (t[i] != t[i - 1]) res++;\

    Q = nextInt<int>();

    while (Q--) {
        int pos, val;
        pos = nextInt<int>();
        val = nextInt<int>();
        change(pos, val);
        printf("%d\n", res);
    }

    return 0;
}
