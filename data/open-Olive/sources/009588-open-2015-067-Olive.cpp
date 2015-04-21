#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const int MAXN = 1e6 + 6, bd = 20, bdv = 1 << bd;

struct vertex {
    int l, r, value;
    vertex(int _l, int _r, int _value) {
        l = _l;
        r = _r;
        value = _value;
    }
    vertex() {
        l = r = value = 0;
    }
};

vertex rsq[MAXN * bd + bdv];

int segtree_sum(int v, int vl, int vr, int l, int r) {
    if (r < vl || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[v].value;
    }
    int vm = (vl + vr) / 2;
    return segtree_sum(rsq[v].l, vl, vm, l, r) + segtree_sum(rsq[v].r, vm + 1, vr, l, r);
}

int c = 0;

int segtree_set(int pos, int num, int parent) {
    int vl = 0, vr = bdv - 1;
    //pos += bdv;
    int v = parent;
    int from = c;
    while (vr != vl) {
        int vm = (vl + vr) / 2;
        if (vm < pos) {
            rsq[c] = vertex(rsq[v].l, c + 1, 0);
            v = rsq[v].r;
            vl = vm + 1;
        } else {
            rsq[c] = vertex(c + 1, rsq[v].r, 0);
            v = rsq[v].l;            
            vr = vm;
        }
        ++c;
    }
    rsq[c] = vertex(-1, -1, num);
    //rsq[c - 1].l = rsq[c - 1].r = -1;
    //rsq[c - 1].value = num;
    ++c;
    for (int i = c - 2; i >= from; --i) {
        rsq[i].value = rsq[rsq[i].l].value + rsq[rsq[i].r].value;
    }
    return from;
}

int n;
int inp[MAXN];
int roots[MAXN];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //int c = 0;
    for (int i = 0; i < bdv; ++i) {
        rsq[c] = vertex(c * 2, c * 2 + 1, 0);
        ++c;
    } 
    for (int i = 0; i < bdv; ++i) {
        rsq[c] = vertex(-1, -1, 0);
        ++c;
    }
    roots[0] = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {        
        scanf("%d", &inp[i]);        
        roots[i + 1] = segtree_set(inp[i], 1, roots[i]);
    }

    //cout << rsq[roots[n]].value << endl;
    //cout << segtree_sum(roots[n], 0, bdv - 1, 1, n) << endl;
    
    pair <int, pii > ans = mapa(0, mapa(-1, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = i + ans.ff + 1; j < n; ++j) {
            if (inp[i] < inp[j]) {
                continue;
            }   
            int num = segtree_sum(roots[j + 1], 0, bdv - 1, inp[j], inp[i]) - segtree_sum(roots[i], 0, bdv - 1, inp[j], inp[i]);
            
            ans = max(ans, mapa(num, mapa(i, j)));
        }
    }   
    
    if (ans.ff == 0) {
        printf("-1 -1\n");
    } else {
        //cout << ans.ss.ff + 1 << " " << ans.ss.ss + 1 << endl;
        printf("%d %d\n", ans.ss.ff + 1, ans.ss.ss + 1);
    }

    return 0;
}
