
// UW forfiters
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
const int max_n = 202;
int win[max_n][max_n];
int lost[max_n][max_n];
int hh[max_n], ht[max_n], th[max_n], tt[max_n];

int outdeg[max_n][max_n];

int main()
{
    int H,t,R,n,m;
    scanf("%d%d%d",&H,&t,&R);
    scanf("%d", &n);
    FOR(i,1,n) { scanf("%d%d",&hh[i],&ht[i]); }
    scanf("%d", &m);
    FOR(i,1,m) { scanf("%d%d",&th[i],&tt[i]); }

    queue<PII> q;
    q.push(MP(0,0));
    CLR(win,-1);
    win[0][0] = 0;
    while (!q.empty()) {
        PII h = q.front(); q.pop();
        FOR(i,1,n) {
            int A = h.FI + i - hh[i];
            int B = h.SE - ht[i];
            if (A >= i && B >= 0 && A + B <= R && win[A][B] == -1) {
                win[A][B] = win[h.FI][h.SE] + 1;
                q.push(MP(A,B));
            }
        }
        FOR(i,1,m) {
            int A = h.FI - th[i];
            int B = h.SE + i - tt[i];
            if (A >= 0 && B >= i && A + B <= R && win[A][B] == -1) {
                win[A][B] = win[h.FI][h.SE] + 1;
                q.push(MP(A,B));
            }
        }
    }

//    FOR(i,0,R) { FOR(j,0,R) printf("%d ",win[i][j]); puts(""); } 

    if (win[H][t] != -1) {
        printf("Ivan\n%d\n",win[H][t]);
        return 0;
    }

    CLR(lost,-1);
    REP(i,max_n) REP(j,max_n) if (i + j > R) {
        lost[i][j] = 0;
    }

    CLR(outdeg, 0);
    REP(i,max_n) REP(j,max_n) if (lost[i][j] == -1) {
        FOR(u,1,min(i,n)) {
            int A = i - u + hh[u];
            int B = j + ht[u];
            if (A + B <= R) ++outdeg[i][j];
        }
        FOR(w,1,min(j,m)) {
            int A = i + th[w];
            int B = j -w + tt[w];
            if (A + B <= R) ++outdeg[i][j];
        }
        if (outdeg[i][j] == 0) {
           q.push(MP(i,j));
           lost[i][j] = 1;
        }
    }

    while (!q.empty()) {
        PII h = q.front(); q.pop();
        FOR(i,1,n) {
            int A = h.FI + i - hh[i];
            int B = h.SE - ht[i];
            if (A >= i && B >= 0 && A + B <= R && lost[A][B] == -1) {
                --outdeg[A][B];
                if (!outdeg[A][B]) {
                    lost[A][B] = lost[h.FI][h.SE] + 1;
                    q.push(MP(A,B));
                }         
            }
        }
        FOR(i,1,m) {
            int A = h.FI - th[i];
            int B = h.SE + i - tt[i];
            if (A >= 0 && B >= i && A + B <= R && lost[A][B] == -1) {
                --outdeg[A][B];
                if (!outdeg[A][B]) {
                    lost[A][B] = lost[h.FI][h.SE] + 1;
                    q.push(MP(A,B));
                }      
            }
        }
    }
/* 
    puts("lost:");
    FOR(i,0,R) { FOR(j,0,R) printf("%d ",lost[i][j]); puts(""); } 
    puts("outdeg:");
    FOR(i,0,R) { FOR(j,0,R) printf("%d ",outdeg[i][j]); puts(""); } 
*/
    if (lost[H][t] != -1) {
        printf("Zmey\n%d\n",lost[H][t]);
    } else {
        puts("Draw");
    }

    return 0;
}
