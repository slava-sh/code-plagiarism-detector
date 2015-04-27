// Author: QCC
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define REP(i,a,b) for( int i=(a),_b=(b);i<_b;++i)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }


typedef pair< int, int > pii;
typedef long long LL;

//const int MAXINT = 2147483647;
//const LL MAXLL = (long long)9223372036854775807;+

struct edge{
    int u, v, c;
    edge(int _u, int _v, int _c) {
        u = _u;
        v = _v;
        c = _c;
    }
};

string s[1111][11];
int n, m, k, w;
vector<edge> e;
int nE;

int dist(string a[], string b[]) {
    int cnt = 0;
    REP(i, 0, n)
    REP(j, 0, m)
        if (a[i][j] != b[i][j]) cnt += w;
    return cnt;
}

bool myCmp(edge a, edge b) {
    return a.c < b.c;
}

int par[150895];
int anc(int p){ if (par[p]==p) return p; else return par[p]=anc(par[p]); }
void join(int p, int q){ par[anc(p)]=anc(q); }

vector<pii> res;
int sum = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k >> w;
    cin.ignore(100000, '\n');
    string root[11];
    nE = 0;
    FOR(i, 1, k) {
        REP(j, 0, n)
            getline(cin, s[i][j]);
        nE++;
        e.pb(edge(0, i, m*n));
    }
    FOR(i, 1, k)
    FOR(j, i+1, k) {
        nE++;
        e.pb(edge(i, j, dist(s[i], s[j])));
        //cout << i << " " << j << " " << dist(s[i], s[j]) << endl;
    }
    sort(e.begin(), e.end(), myCmp);
    for (int i=0; i<=k; i++) par[i]=i;
    vector<edge>::iterator it;
    for (it=e.begin(); it!=e.end(); it++){
        //cout << it -> u << " " << it -> v << " " << it -> c << endl;
        if (anc(it->u) != anc(it->v)){
            //cout << " " << it -> u << " " << it -> v << " " << it -> c << endl;
            join(it->u, it->v);
            sum += it->c;
            res.pb(mp(it->u, it->v));
        }
    }
    cout << sum << endl;
    bool tt[150895];
    memset(tt, true, sizeof(tt));
    int i = res.size()-1;
    cout << res[i].nd << " " << res[i].st << endl;
    int cnt = 1;
    tt[res[i].nd] = false;
    tt[res[i].st] = false;
    while (cnt < res.size()) {
        REP(i, 0, res.size()) {
            if (tt[res[i].nd] == false && tt[res[i].st] == true) {
                cout << res[i].st << " " << res[i].nd << endl;
                tt[res[i].st] = false;
                cnt++;
            }
            if (tt[res[i].st] == false && tt[res[i].nd] == true) {
                cout << res[i].nd << " " << res[i].st << endl;
                tt[res[i].nd] = false;
                cnt++;
            }
        }
        //cout << cnt << endl;
    }
    return 0;
}
