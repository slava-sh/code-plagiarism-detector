
#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>
#include<bitset>

using namespace std;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))
#define INF 1000000000

int a[112345];

struct node {int a,b,c; };
vector <PI> v;
int out[3][112345];

bool check(int num)
{
	int sz = SZ(v);
	int sum = 0;
	REP(i,sz)
	{
		if(v[i].first > num) sum += num;
		else sum += v[i].first;
	}
	if(sum >= 3*num) return true;
	return false;
}

int bin_search(int hi)
{
	int sz = SZ(v);
	int lo = 0;
	while(hi > lo + 1)
	{
		int mid = (hi + lo)/2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	return lo;
}

int main()
{
	int n = SI;
	REP(i,n) a[i] = SI;
	sort(a,a+n);
	for(int i = 0;i<n;)
	{
		int cnt = 1;
		int j;
		for(j = i+1; j<n && a[j-1] == a[j]; ++j) ++cnt;
		v.PB(MP(cnt,a[i]));
		i = j;
	}
	sort(ALL(v));
	int sz = SZ(v);
	int ans = bin_search(n/3+1);
	printf("%d\n",ans);

	int r = 0, c = 0;
	bool flag = false;
	REP(i,sz)
	{
		for(int j = 0; j<v[i].first && j<ans; ++j)
		{
			out[r][c] = v[i].second;
			++c;
			if(c == ans) { c= 0; ++r; 
				if(r == 3) { flag = true;}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	REP(i,ans)
	{
		int t[] = {out[0][i], out[1][i], out[2][i]};
		sort(t,t+3);
		printf("%d %d %d\n",t[2],t[1],t[0]);
	}
	return 0;
}
