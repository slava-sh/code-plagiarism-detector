#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const int N = 100010;

struct tree{
    int l, r, kol, lf, rg;
    tree(int _l = 0, int _r = 0, int _lf = 0, int _rg = 0) {
        l = _l, r = _r;
        kol = 1, lf = _lf, rg = _rg;
    }
} a[4 * N];

int d[N];

void build_tree(int node, int l, int r) {
    a[node] = tree(l, r, d[l], d[r - 1]);
    if(l + 1 == r) {
    } else {
        build_tree(node * 2, l, (l + r) / 2);
        build_tree(1 + node * 2, (l + r) / 2, r);
        a[node].kol = a[node * 2].kol + a[node * 2 + 1].kol - (a[node * 2].rg == a[node * 2 + 1].lf);
    }
}

void update(int node, int l, int c) {
//    cout << a[node].l << ' ' << a[node].r << "\n\t";
//    cout << l << ' ' << c << "\n";
    if(a[node].l == l && a[node].r == l + 1) {
        a[node].lf = a[node].rg = c;
    } else if(a[node].r <= l || a[node].l >= l + 1) {
        return;
    } else {
        update(node * 2, l, c);
        update(1 + node * 2, l, c);
        a[node].kol = a[node * 2].kol + a[node * 2 + 1].kol - (a[node * 2].rg == a[node * 2 + 1].lf);
        a[node].lf = a[node * 2].lf;
        a[node].rg = a[node * 2 + 1].rg;
    }
}


void print() {
    for(int i = 1; i <= 15; i++)
        cout << a[i].l << ' ' << a[i].r << ' ' << a[i].kol << ' '<< a[i].lf << ' ' << a[i].rg << "\n";
}

int main() {
    inp("input.txt");
    must;
    int n, i, q, p, c;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> d[i];
    build_tree(1, 0, n);
    for(cin >> q; q; q--) {
        cin >> p >> c;
        update(1, p - 1, c);
        cout << a[1].kol << "\n";
    }
    return 0;
}




