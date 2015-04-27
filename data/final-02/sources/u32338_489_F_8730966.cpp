#pragma warning( disable : 4996)
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:666000000")

#define bublic public

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include <stack>

#define nextLine() {for(int c=getchar(); c!='\n' && c!=EOF; c=getchar());}
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define set_true(mask, i) (mask|(1<<(i)))
#define set_false(mask, i) (~((~mask)|(1<<(i))))

#define Equal(a, b) (fabsl(a-b) < 1e-9)
#define Less(a, b) (a < b && !Equal(a, b))
#define Greater(a, b) (a > b && !Equal(a, b))

using namespace std;

#ifdef SCHULLZ
#define TASK "file"
#define eprintf(...) fprintf(stdout, __VA_ARGS__)
#define parr(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";puts("");}puts("");
#define log(x) cout << #x << " = " << x << endl
#else
#define TASK "file"
#define eprintf(...) 
#define parr(a,n,m)
#define log(x)
#endif

#define pb(_o_) push_back(_o_)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double ldb;

typedef pair<int,int> pii;
typedef pair<pii,int> tiii;
typedef pair<pii,pii> fiiii;
#define aaa first.first
#define bbb first.second
#define ccc second.first
#define ddd second.second
#define mp(x, y) make_pair(x, y)
#define mpp(x, y, z) make_pair(mp(x, y), z)
#define mppp(x, y, z, a) make_pair(mp(x, y), mp(z, a))

#define sci(a) (1 == scanf("%d", &a))
#define scii(a,b) (2 == scanf("%d%d", &a, &b))
#define sciii(a,b,c) (3 == scanf("%d%d%d", &a, &b, &c))
#define sciiii(a,b,c,d) (4 == scanf("%d%d%d%d", &a, &b, &c, &d))
#define sciiiii(a,b,c,d,e) (5 == scanf("%d%d%d%d%d", &a, &b, &c, &d, &e))

#define scin(a) (1 == scanf("%d\n", &a))
#define sciin(a,b) (2 == scanf("%d%d\n", &a, &b))
#define sciiin(a,b,c) (3 == scanf("%d%d%d\n", &a, &b, &c))
#define sciiiin(a,b,c,d) (4 == scanf("%d%d%d%d\n", &a, &b, &c, &d))
#define sciiiiin(a,b,c,d,e) (5 == scanf("%d%d%d%d%d\n", &a, &b, &c, &d, &e))

#define FORN(i,n) for(int i = 0; i < (int)(n); i++)
#define FORR(i,n) for(int i = n - 1; i >= 0; i--)
#define FORS(it,a) for(auto it = a.begin(); it != a.end(); it++)
#define fill(a,v) memset(a,v,sizeof(a))

typedef vector<int> vi;
typedef vector<vi> vvi;

#ifdef SCHULLZ
typedef vector<int> vc;
typedef vector<vc> vvc;
#else
typedef vector<char> vc;
typedef vector<char> vvc;
#endif

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;

void ML(const bool v)
{
    if (v)
        return;
    int *ass;
    for (;;)
    {
        ass = new int[2500000];
        for (int i = 0; i < 2500000; i++)
            ass[i] = rand();
    }
}

void TL(const bool v)
{
    if (v)
        return;
    for (;;)
        cout << rand() % (rand() % 1000 + 1) << endl;
}

void PE(const bool v)
{
    if (v)
        return;
    for (int i = 0; i < 10000; i++)
        printf("%c", rand() % 256);
    exit(0);
}

char _tmp[100500];

#define read(str) {scanf("%s", _tmp); str = _tmp;}

int n, m, MOD;
vector<string> s;

bool LoAd()
{
    if (!sciii(n, m, MOD))
        return false;
    s.resize(m);
    for (int i = 0; i < m; i++)
        read(s[i]);
    return true;
}

vi cnt;

int sv[505][505];

int add(int a, int b)
{
    return (a + b) % MOD;
}
int mul(int a, int b)
{
    return (a * 1ll * b) % MOD;
}

int go(const int c0, const int c1)
{
    if (c0 < 0 || c1 < 0)
        return 0;
    int &res = sv[c0][c1];
    if (-1 != res)
        return res;
    if (0 == c0 && 0 == c1)
        return res = 1;
    res = 0;
    res = add(res, mul(c0 * (c0 - 1) / 2, go(c0 - 2, c1 + 2)));
    res = add(res, mul(c1 * (c1 - 1) / 2, go(c0    , c1 - 2)));
    res = add(res, mul(c0 * c1          , go(c0 - 1, c1    )));
    return res;
}

void SoLvE()
{
    cnt.assign(n, 0);
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
        int cr = 0;
        FORN(j, n) if ('1' == s[i][j])
        {
            cnt[j]++;
            cr++;
        }
        ok &= (cr == 2);
    }
    if (!ok)
    {
        puts("0");
        return;
    }
    int c0 = 0, c1 = 0, c2 = 0;
    FORN(i, n)
    {
        switch(cnt[i])
        {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        default:
            puts("0");
            return;
            break;
        }
    }
    fill(sv, -1);
    cout << go(c0, c1) << endl;
}

int main()
{
    srand( (int) time(NULL));
#ifdef SCHULLZ
    freopen(TASK".in","r",stdin);   freopen(TASK".out","w",stdout);
    for (int i = 0; LoAd(); i++)
        SoLvE();
#else
    LoAd();
    SoLvE();
#endif
    return 0;
}