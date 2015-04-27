#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cassert>

using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
#define INF (int)1e9
#define EPS LD(1e-9)
#define DINF LD(1e50)

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef double LD;

const int mn=104, mr=252, ms=mr*mn/2;
int n;
LD p[mn];
LD mem[2][ms];

LD bottomup(){
	REP(i,ms)	mem[0][i]=0;
	LD ans=0;
	FOR(rem,1,mr){
		int cur=rem&1;
		REP(sumreq,ms){
			mem[cur][sumreq]=0;
			REP(i,n+1)	if(sumreq>=i)	mem[cur][sumreq]=max(mem[cur][sumreq],p[i]+mem[1-cur][sumreq-i]);
		}
		ans=max(ans,mem[cur][(rem*n)>>1]/rem);
	}
	return ans;
}

int main(){
	
//	freopen("inp.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	cin>>n;
	REP(i,n+1)	cin>>p[i];
	LD ans=bottomup();
	printf("%.9lf\n",ans);
	
//	while(1);
	return 0;
}
