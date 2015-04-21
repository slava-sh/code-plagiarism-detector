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

const int MAX_MEM = (int)4e8;

char mem[MAX_MEM];
size_t usedMem;

void * operator new(size_t sz) {
    void * res = mem + usedMem;
    usedMem += sz;
    return res;
}

void operator delete(void * p) {}


const ll LINF = (ll)1e18;

vector<vector<pair<int, int> > > go;
vector<vector<ll> > dp;

vector<ll> factorize(ll X) {
    vector<ll> f;
    for (ll i = 1; i * i <= X; i++)
        if (X % i == 0) {
            f.push_back(i);
            f.push_back(X / i);
        }
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    return f;
}

void minimize(ll & x, ll y) {
    if (x > y) x = y;
}

//int IT = 0;

void addGO(int x, int y, int z) {
    go[x].push_back(make_pair(y, z));
    go[y].push_back(make_pair(x, z));
    //IT += 2;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    ll N;
    int K;

    cin >> N >> K;

    vector<ll> f = factorize(N);

    //cerr << f.size() << "\n";

    go.resize(f.size());

    size_t fsize = f.size();

    for (size_t i = 0; i < fsize; i++)
        for (size_t j = i; j < fsize; j++)
            if (N % (f[i] * f[j]) == 0) addGO(i, j, lower_bound(f.begin(), f.end(), f[i] * f[j]) - f.begin());

    //cerr << IT << "\n";

    dp.resize(K + 1, vector<ll>(f.size(), LINF));

    dp[0][0] = 1;

    for (int k = 0; k < K; k++)
        for (size_t i = 0; i < fsize; i++) {
            if (dp[k][i] == LINF) continue;
            for (size_t it = 0; it < go[i].size(); it++) {
                minimize(dp[k + 1][go[i][it].second], dp[k][i] * ((f[go[i][it].first] + 1) / 2));
            }
        }

    cout << dp[K][(int)fsize - 1] << "\n";

    return 0;
}
