#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int MX = 300010;
int n, p;
int deg[MX], bit[MX];
vi e[MX];

ll sum(int i){
	ll res = 0;
	for(i++; i; i -= i & -i) res += bit[i];
	return res;
}
void add(int i, int x){
	for(i++; i < MX; i += i & -i) bit[i] += x;
}

int main(){
	scanf("%d%d", &n, &p);
	rep(i, n){
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
	}
	int cnt = 0;
	ll ans = 0;
	
	for(int i = 1; i <= n; i++){
		
		deg[i] = e[i].size();
		add(deg[i], 1);
	}
	
	for(int i = 1; i <= n; i++){
		
		rep(j, e[i].size()){
			add(deg[e[i][j]], -1);
			add(--deg[e[i][j]], 1);
		}
		if(deg[i] >= p) ans += n - 1;
		else{
			ans += n - 1 - sum(p - deg[i] - 1) + (deg[i] <= p - deg[i] - 1);
		}
		
		rep(j, e[i].size()){
			add(deg[e[i][j]], -1);
			add(++deg[e[i][j]], 1);
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
