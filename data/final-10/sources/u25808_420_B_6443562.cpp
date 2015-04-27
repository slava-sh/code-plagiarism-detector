// macros {{{
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) ((1LL) << (long long)(n))
#define FOR(i,c) for (auto i=(c).begin(); i != (c).end(); ++i)
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define REP1(i,a,b) for (int i=(int)(a); i <= (int)(b); ++i)
#define MP make_pair
#define PB push_back

#define Fst first
#define Snd second

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 100005
int vis[MAX];
int pre[MAX];

bool ans[MAX];
int record[MAX][2];

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i)
    {
        char op;
        int id;
        scanf(" %c %d", &op, &id);

        record[i][0] = op == '+' ? 1 : -1;
        record[i][1] = id - 1;
    }

    for (int i = 0; i < m; ++i)
    {
        int id = record[i][1];
        if (vis[id] == 0)
            vis[id] = -record[i][0];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = true;
        sum += vis[i] > 0;
        if (vis[i] != 0) pre[i] = -2;
    }

    int near = sum > 0 ? -1 : -3;
    for (int i = 0; i < m; i++)
    {
        int op = record[i][0];
        int id = record[i][1];

        if (op > 0)
        {
            if (pre[id] <= near) ans[id] = false;

            vis[id] = 1;
            sum ++;
        }
        else 
        {
            sum --;
     //       printf("%d %d\n", id, sum);
            if (sum > 0) ans[id] = false;
            pre[id] = i;
            vis[id] = -1;
        }
        if (sum > 0) near = i;
    }
    for (int i = 0; i < n; ++i)
        if (vis[i] == -1 and pre[i] <= near) ans[i] = false;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += ans[i];

    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i)
        if (ans[i])
            printf("%d ", i+1);
}



