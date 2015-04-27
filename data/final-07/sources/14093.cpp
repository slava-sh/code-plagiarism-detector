#pragma comment(linker, "/STACK:10000000")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define debug(x) {cerr << #x << " = " << x << endl;}
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 300*1000;

int n, m;
pt a[NMAX], add[NMAX];

bool cmp(const pt& a, const pt& b){
    return a.Y < b.Y;
}

void solve(int lf, int rg){
    if(lf==rg)
        return;

    int mid = (lf+rg) >> 1;

    int x_mid = a[mid].X;

    solve(lf, mid);
    solve(mid+1, rg);
    inplace_merge(a+lf, a+mid+1, a+rg+1, cmp);

    fore(i, lf, rg+1){
        int j = i;
        while(j <= rg && a[i].Y == a[j].Y)
            j++;
        add[m++] = pt(x_mid, a[i].Y);
        i = j-1;
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d", &n);
    forn(i, n){
        scanf("%d%d", &a[i].X, &a[i].Y);
    }

    sort(a,a+n); m = 0;
    solve(0, n-1);

    forn(i,n)
        add[m++]= a[i];
    sort(add, add+m);
    m = unique(add, add+m)-add;

    if(m > 2*100*1000) throw;

    printf("%d\n", m);
    forn(i, m)
        printf("%d %d\n", add[i].X, add[i].Y);

    
    return 0;
}

