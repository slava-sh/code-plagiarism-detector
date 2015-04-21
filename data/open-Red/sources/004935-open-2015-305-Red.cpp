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

const int INF = 1e9 + 7;
///=============================================

struct treap {
    struct node {
        int x, y, val, l, r;
        node (int x1 = 0, int y1 = 0, int val1 = 0, int l1 = 0, int r1 = 0) :
            x (x1),
            y (y1),
            val (val1),
            l (l1),
            r (r1)
        {}
    };

    vector <node> t;
    int root;

    treap () : t (1), root (0) {}

    void split (int x, int v, int &l, int &r);
    int merge (int l, int r);
    void insert (int x, int val);
    void erase (int x1, int x2);
    const treap & operator = (const treap &b);
    void obhod (int x1, int x2);
    void obhod_node (int v);
};

#define MAXN int (1.1e5)

treap g[MAXN];
treap g1[MAXN];

struct point {
    int v, temp, dist;

    point (int v1 = 0, int temp1 = 0, int dist1 = 0) :
        v (v1),
        temp (temp1),
        dist (dist1)
    {}
};

unordered_map <int, int> usedT[MAXN];

queue <point> q;
int I;
int cur_dist;

void func (pii edge) {
    if (usedT[edge.one][edge.two] < I) {
        usedT[edge.one][edge.two] = I;
        q.emplace (edge.one, edge.two, cur_dist + 1);
    }
}

INT main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    int n, m, f;

    cin >> n >> m >> f;

    fori (m) {
        int x, y, temp;
        cin >> x >> y >> temp;
        --x; --y;
        g1[x].insert (temp, y);
        g1[y].insert (temp, x);
    }

    int Q;
    cin >> Q;

   for (I = 1; I <= Q; ++I) {
        int start, fin;

        cin >> start >> fin;

        --start;
        --fin;

        fori (n) {
            g[i] = g1[i];
        }

        ///q.clear();
        while (!q.empty()) {
            q.pop();
        }

        q.emplace (start, -INF, 0);

        while (!q.empty()) {
            point cur = q.front();
            q.pop();

            if (cur.v == fin) {
                cout << cur.dist << endl;
                goto next;
            }

            int l, r;
            if (cur.temp == -INF) {
                l = -INF + 1;
                r = INF - 1;
            } else {
                l = cur.temp - f;
                r = cur.temp + f;
            }

            cur_dist = cur.dist;

            g[cur.v].obhod (l, r);
            g[cur.v].erase (l, r);
        }

        cout << -1 << endl;

        next:
        {}
    }

}


void treap::split (int x, int v, int &l, int &r) {
    if (!v) {
        l = r = 0;
        return;
    }
    if (t[v].x > x) {
        split (x, t[v].l, l, t[v].l);
        r = v;
    } else {
        split (x, t[v].r, t[v].r, r);
        l = v;
    }
}

int treap::merge (int l, int r) {
    if (!l || !r)
        return l | r;
    if (t[l].y > t[r].y) {
        t[l].r = merge (t[l].r, r);
        return l;
    } else {
        t[r].l = merge (l, t[r].l);
        return r;
    }
}

void treap::insert (int x, int val) {
    int l, r, m = t.size();

    t.push_back (node (x, rand(), val));

    split (x, root, l, r);
    root = merge (merge (l, m), r);
}

void treap::erase (int x1, int x2) {
    int l, r, m;

    split (x2, root, m, r);
    split (x1 - 1, m, l, m);

    root = merge (l, r);
}

const treap & treap::operator = (const treap &b) {
    t = b.t;
    root = b.root;
    return *this;
}

void treap::obhod (int x1, int x2) {
    int l, r, m;

    split (x2, root, m, r);
    split (x1 - 1, m, l, m);

    obhod_node (m);

    root = merge (merge (l, m), r);
}

void treap::obhod_node (int v) {
    if (!v)
        return;
    obhod_node (t[v].l);
    func (pii (t[v].val, t[v].x));
    obhod_node (t[v].r);
}
