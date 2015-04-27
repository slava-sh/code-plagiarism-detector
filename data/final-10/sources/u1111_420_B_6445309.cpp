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

int n, m, x[100010];
char c[100010];

int main(){
	scanf("%d%d", &n, &m);
	set<int> used, on, ans, cand;
	
	rep(i, m){
		scanf(" %c%d", c + i, x + i);
		if(c[i] == '-'){
			if(!used.count(x[i])) on.insert(x[i]);
		}
		used.insert(x[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(!used.count(i)) ans.insert(i);
		else cand.insert(i);
	}
	
	int last = -1;
	bool ok = 1;
	
	rep(i, m + 1){
		if(c[i] == '+'){
			if(on.size()) cand.erase(x[i]);
			else{
				if(last >= 0 && last != x[i]) ok = 0;
			}
			on.insert(x[i]);
		}
		else{
			on.erase(x[i]);
			if(on.size()) cand.erase(x[i]);
			else last = x[i];
		}
	}
	
	if(ok) each(i, cand) ans.insert(*i);
	printf("%d\n", ans.size());
	each(i, ans) printf("%d ", *i);
	
	return 0;
}
