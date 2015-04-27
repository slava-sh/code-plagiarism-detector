#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
//#include <cassert>
#include <cstring>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <bitset>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define assert(x) if (!(x)) cout << "ASSERT FAILED ON {"#x"}! Line: " << __LINE__ << "\n" << flush, exit(1);
#define assertwt(x) if (!(x)) {cout << "ASSERT FAILED ON {"#x"}! Line: " << __LINE__ << "\n" << flush; while(1);}

#define input_file(s) assert(freopen(s, "r", stdin))
#define output_file(s) assert(freopen(s, "w", stdout))
#define stderr_file(s) assert(freopen(s, "w", stderr))

#ifdef MY
#define FLU cout << flush
#else
#define FLU 42
#endif

#define ALL(a) (a).begin(), (a).end()
#define FORAB(i, a, b) for (int i = a; i < b; ++i)
#define DBG(x) z_dbg << #x" = " << x << "\n", FLU
#ifdef MY
#define CHECKPOINT z_dbg << "At line " << __LINE__ << ", clock: " << clock() << "\n", FLU
#else
#define CHECKPOINT 42
#endif

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;

const double PI = 3.14159265358979323846;
const double EPS = 1e-9;

const int INF = 2e9;
const ll LINF = 1e18;

template<class T>
const T sqr(const T &x) { return x * x; }

template<class T>
const T &min(const T &a, const T &b, const T &c) { return min(min(a, b), c); }

template<class T>
const T &max(const T &a, const T &b, const T &c) { return max(max(a, b), c); }

struct DbgStream {
    template <class T>
    DbgStream &operator<<(const T &x) {
        #ifdef MY
        cout << x;
        #endif
        return *this;
    }
} z_dbg;

#define cerrr cerr
#define cerr z_dbg

// !GLOB

// DSU BEGIN
vector<int> p (5000);

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}
// DSU END

int n, m, k, w;

char a[1001][10][11];

int diff[1001][1001];
int nm;

int ans;
vector<ipair> ans2;

struct Edge {
    int a, b, w;

    bool operator<(const Edge &s) const {
        return w < s.w;
    }
};

vector<Edge> e;

vector<int> de[5000];

bool vis[5000];

void dfs(int v) {
    vis[v] = 1;
    for (int u: de[v]) {
        if (!vis[u]) {
            ans2.push_back({u, v});
            dfs(u);
        }
    }
}

int main() {
    #ifdef MY
    input_file("input.txt");
    //output_file("output.txt");
    //stderr_file("stderr.txt");
    #else
    #define TASK_FILE_NAME "protocol"
    //input_file(TASK_FILE_NAME".in");
    //output_file(TASK_FILE_NAME".out");
    //input_file("input.txt");
    //output_file("output.txt");
    #endif

    ios_base::sync_with_stdio(0);

    // !MAIN

    for (int i = 0; i < 5000; ++i) p[i] = i;

    scanf("%d%d%d%d", &n, &m, &k, &w);

    nm = n * m;

    for (int i = 1; i <= k; ++i) {
        fill(a[0][i], a[0][i] + 10, '$');
        fill(a[i][0], a[i][0] + 10, '$');
        diff[i][0] = diff[0][i] = nm;
        e.push_back({0, i, nm});
        //e.push_back({i, 0, nm}); lol ya lalka
    }

    for (int q = 1; q <= k; ++q) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", a[q][i]);
        }
    }

    for (int q = 1; q <= k; ++q) {
        for (int l = q + 1; l <= k; ++l) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[q][i][j] != a[l][i][j]) {
                        diff[q][l] += w;
                    }
                }
            }
            diff[l][q] = diff[q][l];
            e.push_back({q, l, diff[q][l]});
        }
    }

    sort(e.begin(), e.end());

    /*cerr << e.size() << "\n";
    for (const Edge &e : ::e) {
        cerr << e.a << "->" << e.b << " [" << e.w << "]\n";
    }*/

    for (const Edge &e : ::e) {
        if (dsu_get(e.a) != dsu_get(e.b)) {
            dsu_unite(e.a, e.b);
            ans += e.w;
            de[e.a].push_back(e.b);
            de[e.b].push_back(e.a);
            //cerr << e.a << " " << e.b << "\n";
        }
    }

    dfs(0);

    //cout << ans << "\n";
    printf("%d\n", ans);

    for (const ipair &x : ans2) {
        //cout << x.first << " " << x.second << "\n";
        printf("%d %d\n", x.first, x.second);
    }

    return 0;
}









