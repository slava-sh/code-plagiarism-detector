/*******************\
|* # By longbiau # *|
\*******************/

#define _CRT_SECURE_NO_WARNINGS

// #include C {
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<ctime>
#include<cmath>
// }

// #include C++ {
#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <char, char> PCC;
typedef pair <double, double> PDD;
// }
#ifndef ONLINE_JUDGE
// #parameter{
#define TYPE decltype
/////////////////////////////////////////////////////////////
#else
/////////////////////////////////////////////////////////////
#define TYPE __typeof
// }
#endif
// #define {
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = 2.0*acos(0.0);
const double EPS = 1e-6;

#define GREATER(x, y) ((x) > (y) + EPS)
#define GREATER_EQUAL(x, y) ((x) > (y) - EPS)
#define LESS(x, y) ((x) < (y) - EPS)
#define LESS_EQUAL(x, y) ((x) < (y) + EPS)
#define EQUAL(x, y) (abs((x) - (y)) < EPS)

#define MAX_N 1005
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INT_MAX 2147483647
#define INF (1<<29)
#define BINF (1LL<<60)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
int n, m, k, w;
struct data{
    char mapp[15][15];
}level[MAX_N];
int func[MAX_N][MAX_N];
int G[MAX_N][MAX_N];
int calculate(int idxa, int idxb){
    int sum = 0;
    for (int r = 0; r<n; r++)   for (int c = 0; c<m; c++)   
    if (level[idxa].mapp[r][c] != level[idxb].mapp[r][c]){
        sum += w;
        if (sum >= n*m)
            return n*m;
    }
    return sum;
}
int res[2][MAX_N];
int solve(){
    bitset <MAX_N> used;
    used[1] = true;
    set <int> SS;
    SS.insert(1);
    res[0][0] = 1;
    res[1][0] = 0;
    int total = n*m;
    for (int t = 1; t < k; t++){
        int from = NONE;
        int to = NONE;
        int minn = INF;
        int ff = NONE;
        FOR(itr, SS) for (int v = 1; v <= k; v++) if (!used[v]){
            if (G[*itr][v] < minn){
                from = *itr;
                minn = G[*itr][v];
                ff = func[*itr][v];
                to = v;
            }
        }
        SS.insert(to);
        used[to] = true;
        total += minn;
        res[0][t] = to;
        res[1][t] = ff;
    }
    return total;
}
/////////////////////////////////////////////////////////////
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int lv = 1; lv <= k; lv++){
        for (int r = 0; r < n; r++)
            scanf("%s", level[lv].mapp[r]);
    }
    for (int i = 1; i <= k; i++) for (int j = i + 1; j <= k; j++){
        int rs = calculate(i, j);
        G[i][j] = G[j][i] = rs;
        if (rs < n*m){
            func[i][j] = i;
            func[j][i] = j;
        }
    }
    printf("%d\n", solve());
    for (int i = 0; i < k; i++)
        printf("%d %d\n", res[0][i], res[1][i]);
    return 0;
}