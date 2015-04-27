#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>
#pragma comment(linker, "/STACK:640000000")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e6 + 10;
int x[maxn],y[maxn];
int t[8 * maxn];
int w[2 * maxn],f[2 * maxn];
bool was[maxn];
void update(int l, int r, int pos, int val, int idx) {
    if (l == r) {
        t[idx] += val;
    } else {
        int m = (l + r) >> 1;
        if (pos <= m) {
            update(l,m,pos,val,2 * idx);
        } else {
            update(m + 1,r,pos,val,2 * idx + 1);
        }
        t[idx] = t[2 * idx] + t[2 * idx + 1];
    }
}
int get(int l, int r, int val, int idx) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (t[2 * idx] >= val) return get(l,m,val,2 * idx);
    return get(m + 1,r,val - t[2 * idx],2 * idx + 1);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m; cin >> n >> m;
    memset(w,-1,sizeof(w));
    for (int i = 0; i < m; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    for (int i = m; i < n + m; i++) {
        f[i] = i;
        update(0,n + m - 1,i,1,1);
    }
    for (int i = 0; i < m; i++) {
        int pos = get(0,n + m - 1,y[i],1);
        if ((was[x[i]] && w[pos] != x[i]) || (w[pos] != -1 && w[pos] != x[i])) {
            cout << -1 << endl;
            return 0;
        }
        update(0,n + m - 1,pos,-1,1);
        update(0,n + m - 1,m - i - 1,1,1);
        w[f[pos]] = x[i];
        f[m - i - 1] = f[pos];
        was[x[i]] = true;
        w[m - i - 1] = x[i];
    }
    int j = 1;
    for (int i = m; i < n + m; i++) {
        if (w[i] == -1) {
            while(was[j]) j++;
            printf("%d ",j);
            was[j] = true;
        } else {
            printf("%d ",w[i]);
        }
    }
    return 0;
}
