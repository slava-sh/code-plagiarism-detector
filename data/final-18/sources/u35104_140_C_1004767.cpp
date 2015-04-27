// Author: Ernesto Carvajal Lastres. Madrid, Spain.
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define contains(c,x) (find(all(c),x) != (c).end())
#define oo (1LL << 28)
template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline void checkmin(T& a,T b) { if(b < a) a = b; }
template<class T> inline void checkmax(T& a,T b) { if(b > a) a = b; }
const double eps = 1e-10;
inline int dcmp(double x){ return x < -eps ? -1 : x > eps; }
inline bool deq (double x, double y){ return dcmp(x - y) == 0; }
inline bool dleq(double x, double y){ return dcmp(x - y) <= 0; }
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef long long int64;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vi balls(n);
    rep(i,n) cin >> balls[i];
    sort(all(balls));
    set< pii,greater<pii> > S;
    rep(i,n)
    {
        pii p(1,balls[i]);
        while (i < (n - 1) && balls[i + 1] == p.second)
        {
            p.first++;
            i++;
        }
        S.insert(p);
    }
    vvi sol;
    while (S.size() >= 3)
    {
        pii m1 = *S.begin(); S.erase(S.begin());
        pii m2 = *S.begin(); S.erase(S.begin());
        pii m3 = *S.begin(); S.erase(S.begin());
        vi man; man.pb(m1.second); man.pb(m2.second); man.pb(m3.second);
        sort(all(man), greater<int>());
        sol.pb(man);
        m1.first--; m2.first--; m3.first--;
        if (m3.first > 0) S.insert(m3);
        if (m2.first > 0) S.insert(m2);
        if (m1.first > 0) S.insert(m1);
    }
    cout << sz(sol) << endl;
    fore(man,sol)
        cout << (*man)[0] << ' ' << (*man)[1] << ' ' << (*man)[2] << endl;
    return 0;
}
