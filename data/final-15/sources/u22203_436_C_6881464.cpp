/*==================================================*\
 | Author: ziki
 | Created Time: 
 | File Name: 
 | Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
 
using namespace std;
using namespace rel_ops;
 
typedef long long int64;
typedef long long ll;
typedef unsigned long long uint64;
typedef unsigned long long ull;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<int(n); i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define sz(x) int(x.size())
#ifdef LOCAL
#define dbg(args...) printf(args); //##__VA_ARGS__
#define dout cout
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#else
#define dbg(...)
#define dout if(true);else cout
#define out(...)
#define show(...)
#endif

const int N = 1005;
int n, x, y, w;
char ch[N][11][11];

vector<pair<int, int> > pr;
namespace PRIM {
    const int MAXN = N;
    const int MAXV = 0x3F3F3F3F;
    int n,m,t,x,y,z,c,n1,m1,n2,m2;
    int dis[MAXN][MAXN],low[MAXN],near[MAXN], belong[MAXN];
    int prim(int n) {
        int sum = 0;
        near[1] = -1;
        for(int i = 2;i <= n;i++) {
            low[i] = dis[1][i];//第1个点到其他点的代价
            near[i] = 1;//初始时,所有点的起点都是点1 
        }
        pr.PB(MP(1,0));
        int k = 1;
        for(int i = 2;i <= n;i++) {
            int min = MAXV;//MAXV一个很大的数
            for(int j = 2;j <= n;j++)
                if(near[j] >= 0 && low[j] < min) {
                    min = low[j];//在v中找到最小的代价点
                    k = j;
                }
            //printf("(%d %d)\n",near[k],k);//near[k]->起点,k->终点
            if (low[k] == ::x * ::y) {
                pr.PB(MP(k, 0));
            }
            else {
                pr.PB(MP(k, near[k]));
            }
            sum += low[k];
            near[k] = -1;//k点归入u中
            for(int j = 2;j <= n;j++)
                if(near[j] >=0 && dis[k][j] < low[j]) {
                    low[j] = dis[k][j];//以k点为起点进行新一轮的代价计算
                    near[j] = k;
                }
        }
        for (int i = 1;i <= n;i++)
            if (near[i] >= 0)
                return -1;
        return sum;
    }
}
int main() {
    while (~scanf("%d%d%d%d", &x, &y, &n, &w)) {
        for (int i = 1; i <= n; i++) {
            rep(j, x) scanf("%s", ch[i][j]); 
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int &t = PRIM::dis[i][j];
                t = 0;
                rep(u, x) rep(v, y)
                    t += ch[i][u][v] != ch[j][u][v];
                t *= w;
                if (t > x * y) t = x * y;
            }
        }
        printf("%d\n", PRIM::prim(n) + x * y);
        rep(i, pr.size()) {
            printf("%d %d\n", pr[i].ff, pr[i].ss);
        }
    }
    return 0;
}
