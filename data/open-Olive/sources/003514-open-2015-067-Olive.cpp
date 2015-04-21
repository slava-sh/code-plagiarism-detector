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

int n;
pii rmq[bdv * 2];
int rsq[bdv * 2];
int where[MAXN];

int segtree_segplus(int v, int vl, int vr, int l, int r, int num) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rsq[v] += num;
        return 0;
    }
    int vm = (vl + vr) / 2;
    segtree_segplus(v * 2, vl, vm, l, r, num);
    segtree_segplus(v * 2 + 1, vm + 1, vr, l, r, num);
    return 0;
}

int segtree_get(int pos) {
    pos += bdv;
    int ret = 0;
    while (pos > 0) {
        ret += rsq[pos];
        pos /= 2;
    }
    return ret;
}

int segtree_set(int pos, pii what) {    
    rmq[pos + bdv] = what;
    pos += bdv;
    pos /= 2;
    while (pos > 0) {
        rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

pii segtree_max(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return mapa(-1, -1);
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return max(segtree_max(v * 2, vl, vm, l, r), segtree_max(v * 2 + 1, vm + 1, vr, l, r));
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    pair <int, pii > ans = mapa(0, mapa(-1, -1));
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        where[num] = i;
        pii pos = segtree_max(1, 0, bdv - 1, num, n);
        
        //cout << i << " " << pos.ff << " " << pos.ss << endl;
        ans = max(ans, mapa(pos.ff, mapa(pos.ss, i)));
        //segtree_segplus(1, 0, bdv - 1, num, n, num);
        if (pos.ff) {
            segtree_set(num, mapa(pos.ff + 1, pos.ss));
        } else {
            segtree_set(num, mapa(1, num));
        }
    }

    if (ans.ff == 0) {
        printf("-1 -1\n");
    } else {
        printf("%d %d\n", where[ans.ss.ff] + 1, ans.ss.ss + 1);
    }

    return 0;
}
