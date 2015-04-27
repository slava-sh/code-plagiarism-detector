#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF 1.0E+9

double p[110];
double dp[210];

double func(int N, double x){
    int i,j,k;
    
    REP(i,2*N+1) dp[i] = -INF;
    dp[N] = 0.0;
    
    REP(i,2*N+10) REP(j,2*N+1) REP(k,N+1) if(j-N+2*k >= 0 && j-N+2*k <= 2*N){
        int tmp = j-N+2*k;
        dp[tmp] = max(dp[tmp],dp[j]+p[k]-x);
    }
    
    return dp[N];
}

int main(void){
    int N,i,j,iter;
    
    cin >> N;
    REP(i,N+1) cin >> p[i];
    
    double high = 1.0, low = 0.0, mid;
    REP(iter,25){
        mid = (high + low) / 2.0;
        if(func(N,mid) > 0.0) low = mid; else high = mid;
    }
    
    printf("%.9f\n",mid);
    
    return 0;
}
