/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(515);

int col[MAXN];

long long dp[MAXN][MAXN];

int main(){

    int n,m,mod;
    S("%d%d%d",&n,&m,&mod);
    REP(i,m)
    {
        string a;
        cin >> a;
        REP(j,n)
        {
            if(a[j] == '1')
                col[j]++;
        }
    }

    int num1 = 0;
    REP(j,n)
        num1 += (col[j] == 1);

    dp[0][num1] = 1;

    FOR(i,1,n-m)
        FOR(j,0,n)
        {
            int c1, c2;

            if(j-2 >= 0)
            {
                c1 = ((m+i-1)*2-(j-2))/2, c2 = n-(j-2)-c1;
                dp[i][j] += dp[i-1][j-2] * (c2*(c2-1)/2);
                dp[i][j] %= mod;
            }

            c1 = ((m+i-1)*2-j)/2, c2 = n-j-c1;

            dp[i][j] += dp[i-1][j] * (c2*j);
            dp[i][j] %= mod;

            dp[i][j] += dp[i-1][j+2] * ((j+2)*(j+1)/2);
            dp[i][j] %= mod;
        }

    cout << dp[n-m][0];
}
