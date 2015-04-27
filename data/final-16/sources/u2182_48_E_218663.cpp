#include <algorithm> 
#include <string> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <iostream> 
#include <iterator> 
#include <sstream> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <numeric>
#include <memory.h> 
#include <iomanip>
#include <fstream>

using namespace std; 

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++) 
#define REP(i,n) FOR(i,0,n) 
#define pb push_back 
#define sz size() 

#define ALL(c) (c).begin(), (c).end() 
#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT((c)), (c).erase(unique(ALL((c))), (c).end())
#define MAX(a,b) (((a) > (b)) ? (a) : (b))  
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MP(a,b)  make_pair((a), (b))
#define SQR(a) ((a)*(a))
#define X first
#define Y second

typedef pair<int,int> ii;
typedef vector<int > vi;
typedef vector<vi > vvi;
typedef vector<ii  > vii;
typedef vector<vii  > vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b){return a == 0 ? b : gcd(b%a, a);}

string filename = "test";

ii head[202], tail[202];
int R, n, m;

int mem[400][400];

int go(int h, int t) {
    if (h + t > R) {
        return 0;
    }
    if (mem[h][t] != -1)
        return mem[h][t];

    int& ret = mem[h][t];
    ret = 0;

    FOR(ih, 1, MIN(h, n) + 1) {
        int h1 = h - ih + head[ih].first;
        int t1 = t + head[ih].second;

        int r1 = go(h1, t1);
        if (r1 > ret)
            ret = r1;
    }

    FOR(it, 1, MIN(t, m) + 1) {
        int h1 = h + tail[it].first;
        int t1 = t - it + tail[it].second;

        int r1 = go(h1, t1);
        if (r1 > ret)
            ret = r1;
    }
    ++ret;

    return ret;
}

int D[202][202];

typedef pair<int, ii > iii;

bool cycle = false;

void dfs(int h, int t) {
    if (h + t > R)
        return;
    if (h == 0 && t == 0)
        return;
    if (cycle)
        return;

    D[h][t] = 0;

    FOR(ih, 1, MIN(h, n) + 1) {
        int h1 = h - ih + head[ih].first;
        int t1 = t + head[ih].second;

        if (h1 + t1 <= R) {
            if (D[h1][t1] == 0) {
                cycle = true;
                return;
            } else if (D[h1][t1] == -1) {
                dfs(h1, t1);
                if (cycle)
                    return;
            }
        }
    }

    FOR(it, 1, MIN(t, m) + 1) {
        int h1 = h + tail[it].first;
        int t1 = t - it + tail[it].second;

        if (h1 + t1 <= R) {
            if (D[h1][t1] == 0) {
                cycle = true;
                return;
            } else if (D[h1][t1] == -1) {
                dfs(h1, t1);
                if (cycle)
                    return;
            }
        }
    }

    D[h][t] = 1;
}


int main(){
    //freopen(filename.c_str(), "r", stdin);
    //freopen(filename.c_str(), "w", stdout);

    int h, t;
    scanf("%d %d %d", &h, &t, &R);
    scanf("%d", &n);
    REP(i, n)
        scanf("%d %d", &head[i + 1].first, &head[i + 1].second);
    scanf("%d", &m);
    REP(i, m)
        scanf("%d %d", &tail[i + 1].first, &tail[i + 1].second);

    memset(D, -1, sizeof(D));
    set<iii> Q;
    D[h][t] = 0;
    Q.insert(iii(0, ii(h, t)));

    while(!Q.empty()) {
       iii top = *Q.begin();
       Q.erase(Q.begin());
       ii v = top.second;
       int d = top.first;

       if (v.first == 0 && v.second == 0)
           break;
       if (v.first + v.second > R)
           continue;

       FOR(hi, 1, MIN(n, v.first) + 1) {
           ii v2(v.first - hi + head[hi].first, v.second + head[hi].second);
           if (v2.first + v2.second <= R) {
               if (D[v2.first][v2.second] == -1 || D[v2.first][v2.second] > d + 1) {
                   if (D[v2.first][v2.second] != -1)
                       Q.erase(Q.find(iii(D[v2.first][v2.second], v2)));
                   D[v2.first][v2.second] = d + 1;
                   Q.insert(iii(d + 1, v2));
               }
           }
       }

       FOR(ti, 1, MIN(m, v.second) + 1) {
           ii v2(v.first + tail[ti].first, v.second - ti + tail[ti].second);
           if (v2.first + v2.second <= R) {
               if (D[v2.first][v2.second] == -1 || D[v2.first][v2.second] > d + 1) {
                   if (D[v2.first][v2.second] != -1)
                       Q.erase(Q.find(iii(D[v2.first][v2.second], v2)));
                   D[v2.first][v2.second] = d + 1;
                   Q.insert(iii(d + 1, v2));
               }
           }
       }
    }

    if (D[0][0] != -1) {
        printf("Ivan\n%d\n", D[0][0]);
        return 0;
    }


    memset(D, -1, sizeof(D));
    cycle = false;
    dfs(h, t);
    if (cycle) {
        printf("Draw\n");
        return 0;
    }

    memset(mem, -1, sizeof(mem));
    int res = go(h, t);
    printf("Zmey\n%d\n", res);

    return 0;
}