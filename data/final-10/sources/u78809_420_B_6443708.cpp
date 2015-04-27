//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

vector<PII> v[100005];
int last[100005];
int add[100005];
int mx[100005<<2];

class SegTree{
public:
	int ql,qr;
	void init(int n){
		build(1,n,1);
	}

	void build(int l,int r,int rt){
		if(l==r) mx[rt] = add[l];
		else{
			int mid = (l+r)>>1;
			build(lson);
			build(rson);
			mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);
		}
	}

	int query(int l,int r,int rt){
		if(ql<=l&&r<=qr) return mx[rt];
		else{
			int mid = (l+r)>>1;
			int ans = 0;
			if(ql<=mid) ans = max(ans,query(lson));
			if(mid<qr) ans = max(ans,query(rson));
			return ans;
		}
	}

} seg;

bool check(int pos,int m){
	int sz = v[pos].size();
	if(v[pos][0].first=='+'){
		if(add[0]) return false;
	}
	int in = 0;
	if(v[pos][0].first=='-') in = 1;
	int last = 1;
	for(int i = 0;i<sz;i++){
		if(!in){
			seg.ql = last,seg.qr = v[pos][i].second-1;
			if(seg.ql<=seg.qr){
				int x = seg.query(1,m,1);
				if(x>0) return false;
			}
		}
		last = v[pos][i].second;
		in^=1;
	}
	if(!in){
		seg.ql = last,seg.qr = m;
		if(seg.ql<=seg.qr){
				int x = seg.query(1,m,1);
				if(x>0) return false;
		}
	}
	return true;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> ans;
	memset(last,-1,sizeof(last));
	for(int i = 1;i<=m;i++){
		int x;
		char s[5];
		scanf("%s %d",s,&x);
		if(s[0]=='+'){
			last[x] = 1;
			add[i]++;
		}else if(s[0]=='-'){
			if(last[x]==-1){
				add[0] = 1;
				add[1]++,add[i]--;
			}
			else{
				add[i]--;
			}
			last[x] = 0;
		}
		v[x].PB(MP((int)s[0],i));
	}
	int now = 0;
	for(int i = 1;i<=m;i++){
		now+=add[i];
		add[i] = now;
	}
	seg.init(m);
	for(int i = 1;i<=n;i++){
		if(v[i].size()==0) ans.PB(i);
		else if(check(i,m)){
			ans.PB(i);
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0;i<(int)ans.size();i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}
