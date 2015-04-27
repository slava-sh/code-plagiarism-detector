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

const int MX = 1 << 21;
int bit[MX];
inline int sum(int i){
	int res = 0;
	for(i++; i; i -= i & -i) res += bit[i];
	return res;
}
inline void add(int i, int x){
	for(i++; i < MX; i += i & -i) bit[i] += x;
}
inline int find(int k){
	int lo = 0, hi = MX, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(bit[mid] >= k) hi = mid;
		else lo = mid, k -= bit[mid];
	}
	return hi - 1;
}

int n, m;
int ans[MX];
vector<pi> v;

int main(){
	bool ok = 1;
	
	scanf("%d%d", &n, &m);
	v.resize(n);
	rep(i, n){
		v[i] = mp(n - i - 1, -1);
		add(i, 1);
	}
	
	rep(i, m){
		int x, y;
		scanf("%d%d", &x, &y);
		y--;
		
		int pos = find(n - y);
		if(v[pos].second >= 0 && v[pos].second != x) ok = 0;
		v[pos].second = x;
		
		v.pb(v[pos]);
		v[pos] = mp(-1, -1);
		add(pos, -1);
		add(n + i, 1);
	}
	
	memset(ans, -1, sizeof(ans));
	set<int> unused;
	
	rep(i, n) unused.insert(i + 1);
	rep(i, n){
		int pos = find(n - i); 
		
		//dbg(pos);
		//cerr<<v[pos].first<<" "<<v[pos].second<<endl;
		
		if(v[pos].second < 0) continue;
		if(ans[v[pos].first] >= 0 || !unused.count(v[pos].second)) ok = 0;
		
		ans[v[pos].first] = v[pos].second;
		unused.erase(v[pos].second);
	}
	
	if(!ok){
		puts("-1");
		return 0;
	}
	
	rep(i, n){
		if(ans[i] < 0){
			ans[i] = *unused.begin();
			unused.erase(unused.begin());
		}
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	
	
	return 0;
}
