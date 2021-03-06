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
#define int ll

typedef pair <int, int> pii;
#define one first
#define two second

#define qfor(i, a, b) for (int i = a; i < int (b); ++i)
#define fori(n) qfor (i, 0, n)
#define forj(n) qfor (j, 0, n)

#define cont(v) v.begin(), v.end()

template <class T>
inline T sqr (const T & x) {
    return x * x;
}

const ld EPS = 1e-9L;
const int INF = 1e9L + 7;
const ll BIGINF = 2e18L;

inline bool equal (ld a, ld b) {
    return abs (a - b) < EPS;
}

struct line {
    int a, b, c;

    line (int a1 = 0, int b1 = 0, int c1 = 0) :
        a (a1),
        b (b1),
        c (c1)
    {}

    line (pii q, pii w) :
        a (q.two - w.two),
        b (w.one - q.one),
        c (q.one * w.two - w.one * q.two)
    {}

    ld get_y (ld x) {
        return - ld (c + a * x) / ld (b);
    }
};
///=============================================

const int MAXN = int (1e5) + 100;
const int MAXL = int (4.1e5);

typedef pair <pii, pii> seg;

bool cross (const seg &a, const seg &b) {
    int x1 = max (a.one.one, b.one.one);
    int x2 = min (a.two.one, b.two.one);

    line q (a.one, a.two);
    line w (b.one, b.two);

    ld y11 = q.get_y (x1);
    ld y12 = w.get_y (x1);

    ld y21 = q.get_y (x2);
    ld y22 = w.get_y (x2);

    if ((y11 > y12 && y21 < y22) || (y11 < y12 && y21 > y22)) {
        return 1;
    } else {
        return 0;
    }
}

struct event {
    int x, num, type;

    static const int CLOSE = 0;
    static const int OPEN = 1;

    event (int x1 = 0, int num1 = 0, int type1 = 0) :
        x (x1),
        num (num1),
        type (type1)
    {}

    bool operator < (const event &b) const {
        if (x != b.x)
            return x < b.x;
        if (type != b.type)
            return type < b.type;
        return num < b.num;
    }
};



INT main () {
   // freopen ("_test.c", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    {int a, b;
    cin >> a >> b;}

    int n;

    cin >> n;

    vector <seg> edge;
    vector <event> line;
    vector <int> edge_num;

    fori (n) {
        int l;
        cin >> l;

        static int x[MAXL], y[MAXL];

        forj (l + 1) {
            cin >> x[j] >> y[j];
        }

        forj (l) {
            line.push_back (event (x[j], edge.size(), event::OPEN));
            line.push_back (event (x[j + 1], edge.size(), event::CLOSE));

            edge.push_back (seg (pii (x[j], y[j]), pii (x[j + 1], y[j + 1])));
            edge_num.push_back (i);
        }
    }

    sort (line.begin(), line.end());

    set <int> q;

    fori (line.size()) {
        if (line[i].type == event::CLOSE) {
            q.erase (line[i].num);
        }

        for (set <int> :: iterator it = q.begin(); it != q.end(); ++it) {
            if (cross (edge[line[i].num], edge[*it])) {
                cout << "No" << endl << edge_num[*it] + 1 << " " << edge_num[line[i].num] + 1;
                return 0;
            }
        }

        if (line[i].type == event::OPEN) {
            q.insert (line[i].num);
        }
    }

    cout << "Yes";
}

