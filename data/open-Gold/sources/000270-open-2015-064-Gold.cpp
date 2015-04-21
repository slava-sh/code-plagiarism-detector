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

const int maxn = 200500;
const ll LINF = (ll)1e18;

int N, K, C, D, clen;
ll a[maxn], b[maxn], c[maxn];
ll best = LINF, cur;
int kl;

void upd(ll x) {
    if (best > x) best = x;
}

void addKL(int delta) {
    if (kl != 0) cur -= 1LL * ((kl - 1) / K) * C;
    kl += delta;
    cur += 1LL * ((kl - 1) / K) * C;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    N = nextInt<int>();
    K = nextInt<int>();
    C = nextInt<int>();
    D = nextInt<int>();

    for (int i = 1; i <= N; i++) {
        a[i] = nextInt<int>();
        b[i] = nextInt<int>();
        cur += ll(b[i] - a[i]) * D;
    }

    for (int i = 1; i + 1 <= N; i++) {
        c[++clen] = a[i + 1] - b[i];
    }

    addKL(N);

    sort(c + 1, c + clen + 1);

    upd(cur);

    for (int i = 1; i <= clen; i++) {
        addKL(-1);
        cur += 1LL * c[i] * D;
        upd(cur);
    }

    cout << best << "\n";

    return 0;
}
