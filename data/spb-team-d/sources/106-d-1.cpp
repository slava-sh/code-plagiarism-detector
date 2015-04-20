#include <iostream>
#include <stdio.h>
#include <vector>

#define mp make_pair
#define ll long long

using namespace std;

struct node{
    vector<pair<int, int> > a;
    node *l, *r;
    node() { l = r = NULL; }
};

node* Head = NULL;

void add(node*& v, int tl, int tr, int l, int r, int x) {
    //cout << tl << ' ' << tr << ' ' << l << ' ' << r << ' ' << x << endl;
    if (l > r) {
        v = new node;
        return;
    }
    if (v == NULL)
        v = new node;
    if (tl == l && tr == r) {
        v->a.push_back(mp(x, l));
        return;
    }
    int tm = (tl + tr) / 2;
    add(v->l, tl, tm, l, min(tm, r), x);
    add(v->r, tm + 1, tr, max(tm + 1, l), r, x);
}

int even(int x) {
    if (x % 2 == 0)
        return 1;
    return -1;
}

ll get(node*& v, int tl, int tr, int pos, ll res = 0) {
    //cout << tl << ' ' << tr << ' ' << pos << ' ' << res << endl;
    if (v == NULL)
        return res;
    //cout << "Where is my money?!\n";
    if (tl == tr) {
        for (int i = 0; i < v->a.size(); ++i)
            res += v->a[i].first * even(pos - v->a[i].second);
        return res;
    }

    for (int i = 0; i < v->a.size(); ++i)
        res += v->a[i].first * even(pos - v->a[i].second);

    int tm = (tl + tr) / 2;
    if (tm >= pos)
        return get(v->l, tl, tm, pos, res);
    else
        return get(v->r, tm + 1, tr, pos, res);
}

int main() {
    freopen("dunes.in", "r", stdin);
    freopen("dunes.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0, l, r, x; i < n; ++i) {
        cin >> l >> r >> x;
        --l, --r;
        add(Head, 0, 1e9, l, r, x);
    }

    //*
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        --x;
        cout << get(Head, 0, 1e9, x) << endl;
        //return 0;
    }
    //*/

    return 0;
}
