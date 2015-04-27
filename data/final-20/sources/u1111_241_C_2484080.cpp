#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

const int inf=(int)1e9;
const double INF=1e12, EPS=1e-9;

int v[100], a[100], b[100];
char t[100];

void run()
{
	int hl, hr, n;
	cin >> hl >> hr >> n;
	rep(i, n){
		cin >> v[i] >> t[i] >> a[i] >> b[i];
	}
	
	int ans = 0;
	for(int it = -n; it <= n; it++){
		
		int gy = 100 * it + ((it % 2 == 0)? hr : 100 - hr);
		double p = (gy - hl) / 100000.0;
		int prev = -1, tmp = 0;
		
		bool vis[100] = {};
		rep(i, abs(it)){
			double y = (it > 0 ? 100 : -100) * (i + (it > 0));
			double x = (y - hl) / p;
			
			bool ok = 0;
			rep(j, n){
				if((t[j] == 'T') ^ (i % 2 == 0) ^ (it > 0)){
					
					if(!(a[j] <= x && x <= b[j])) continue;
					
					if(vis[j]) goto FAIL;
					vis[j] = 1;
					ok = 1;
					tmp += v[j];
				}
			}
			if(!ok) goto FAIL;
		}
		ans = max(ans, tmp);
		FAIL:;
	}
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	//int cs=3;rep(i,cs)
#endif
	run();
}
