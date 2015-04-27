#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <numeric>
#include <functional>
#include <valarray>
#include <complex>
#include <utility>
using namespace std;

const int dx[]={0,-1,0,1,-1,1, 1,-1};
const int dy[]={1,0,-1,0, 1,1,-1,-1};
const double eps=1e-8;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vgraph;
typedef vector<pii> vpii;
typedef vector<LL> vLL;
typedef vector<string> vs;

#define sz(a) (int)a.size()
#define fori(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define ford(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define forn(i,n) fori(i,0,n-1)
#define fora(i,a) forn(i,sz(a))
#define fore(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clear0(a) memset(a,0,sizeof(a))
#define clearm1(a) memset(a,-1,sizeof(a))
#define maximum(a) (*max_element(all(a)))
#define minimum(a) (*min_element(all(a)))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) ((S)&two(X))
#define setbit(S,X) ((S)|=two(X))
#define clearbit(S,X) ((S)&=~two(X))
#define togglebit(S,X) ((S)^=two(X))
#define sqr(a) ((a)*(a))
#define finp "input.inp"
#define fout "output.out"
#define nmax 100
#define mmax 100
#define kmax 10
#define modulo 1000000007
#define maxc 999999999

#define debugprint(a) cout << a << ' '
template <typename T>
void debugprintarr(T arr,int x, int y)
{
    fori(i,x,y) debugprint(arr[i]);
    cout << '\n';
}

template <typename T>
void debugprint2darr(T arr, int x1, int y1, int x2, int y2)
{
    fori(i,x1,y1) debugprintarr(arr[i],x2,y2);
}

int n, m, mod;
int Count(const string& s)
{
    int ret = 0;
    for(int i = 0; i < s.length(); ++i)
        if (s[i] == '1')
        ++ret;

    return ret;
}

struct data
{
    int c1, c2;
    data(int x, int y, int z)
    {
        c1 = x;
        c2 = y;
        //row = z;
    }
};

int row[1111], col[1111];
queue<pair<int, int> > q[2];
long long f[555][555][2];
//int gt[555][555][2];
int fr[555][555];
int frr = 1;
int main()
{
        #ifndef ONLINE_JUDGE
              //  freopen(finp,"r",stdin);
             //   freopen(fout,"w", stdout);
        #endif

        cin >> n >> m >> mod;
        int maxx = 0;
        for(int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            for(int j = 0; j < n; ++j)
            {
                row[i] += s[j] - '0';
                col[j] += s[j] - '0';

            }



        }

        int c2, c1;
        c2 = c1 = 0;
        for(int j = 0; j < n; ++j)
            if (col[j] == 0)
                ++c2;
            else
            if (col[j] == 1)
                ++c1;

        int flag = 0;
        f[c1][c2][flag] = 1;
        fr[c1][c2] = frr;
        q[flag].push(make_pair(c1, c2));
        for(int i = m; i < n; ++i)
        {
            int next = 1 - flag;
            ++frr;
            while (!q[flag].empty())
            {

                int c1 = q[flag].front().first;
                int c2 = q[flag].front().second;
                long long gt = f[c1][c2][flag];
                q[flag].pop();

                // 1 1
                if (c1 > 0 && c2 > 0)
                {
                    //c2 giam, c1 giu nguyen
                    long long gtt = gt*c1%mod *c2 %mod;
                    if (fr[c1][c2-1] < frr)
                    {
                        f[c1][c2-1][next] = gtt;
                        fr[c1][c2-1] = frr;
                        q[next].push(make_pair(c1, c2-1));
                    }
                    else
                    {
                         f[c1][c2-1][next] += gtt;
                         f[c1][c2-1][next] %= mod;
                    }

                }

                //2 0
                if (c1 > 1)
                {

                    long long gtt = c1*(c1-1)/2 % mod;
                    gtt = (gtt * gt) % mod;
                    if (fr[c1-2][c2] < frr)
                    {
                        f[c1-2][c2][next] = gtt;
                        fr[c1-2][c2] = frr;
                        q[next].push(make_pair(c1-2, c2));
                    }
                    else
                    {
                        f[c1-2][c2][next] += gtt;
                        f[c1-2][c2][next] %= mod;
                    }
                }

                //0 2
                if (c2 > 1)
                {
                    long long gtt = c2*(c2-1)/2 % mod;
                    gtt = (gtt * gt) % mod;
                    if (fr[c1+2][c2-2] < frr)
                    {
                        f[c1+2][c2-2][next] = gtt;
                        fr[c1+2][c2-2] = frr;
                        q[next].push(make_pair(c1+2, c2-2));
                    }
                    else
                    {
                        f[c1+2][c2-2][next] += gtt;
                        f[c1+2][c2-2][next] %= mod;
                    }
                }
            }
            flag = next;

        }

        if (fr[0][0] == frr)
            cout << f[0][0][flag];
        else
            cout << 0;


        return 0;
}
