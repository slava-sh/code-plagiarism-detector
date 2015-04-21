#define _USE_MATH_DEFINES

#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int INT;
//#define int ll

typedef pair <int, int> pii;
#define one first
#define two second

#define qfor(i, a, b) for (int i = a; i < int (b); ++i)
#define fori(n) qfor (i, 0, n)
#define forj(n) qfor (j, 0, n)

#define cont(v) v.begin(), v.end()

template <class T>
const T & sqr (const T & x) {
    return x * x;
}

const ll INF = 1e9 + 7;
///=============================================

#define MAXN int (1.1e5)

vector <pii> g[MAXN];

struct point {
    int v, temp, dist;

    point (int v1 = 0, int temp1 = 0, int dist1 = 0) :
        v (v1),
        temp (temp1),
        dist (dist1)
    {}
};

ll myhash (const pii &a) {
    return a.one * INF + a.two;
}

unordered_set <ll> used (2 * MAXN);

INT main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    int n, m, f;

    cin >> n >> m >> f;

    fori (m) {
        int x, y, temp;
        cin >> x >> y >> temp;
        g[--x].emplace_back (--y, temp);
        g[y].emplace_back (x, temp);
    }

    int Q;
    cin >> Q;

    qfor (I, 0, Q) {
        int start, fin;

        cin >> start >> fin;

        --start;
        --fin;

        queue <point> q;

        used.clear();

        q.emplace (start, -INF, 0);
        used.insert (myhash (pii (start, -INF)));

        while (!q.empty()) {
            point cur = q.front();
            q.pop();

            //cerr << cur.v << endl;

            if (cur.v == fin) {
                cout << cur.dist << endl;
                goto next;
            }

            fori (g[cur.v].size()) {
                pii edge = g[cur.v][i];
                if (!used.count (myhash (edge)) && (cur.temp == -INF || abs (cur.temp - edge.two) <= f)) {
                    used.insert (myhash (edge));
                    q.emplace (edge.one, edge.two, cur.dist + 1);
                }
            }
        }

        cout << -1 << endl;

        next:
        {}
    }

}

