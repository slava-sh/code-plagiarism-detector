#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int tree[MaxN];
void ins(int idx, int val) {
	for (int z = idx; z <= 1000000; z += z & -z) tree[z] += val;
}

int ask(int r) {
	int ret = 0;
	for (int z = r; z; z -= z & -z) ret += tree[z];
	return ret;
}

int v[MaxN],next[MaxN],h[MaxN],tot = 0;
void add(int b,int e) {
	v[++tot] = e; next[tot] = h[b]; h[b] = tot;
	v[++tot] = b; next[tot] = h[e]; h[e] = tot;
}

int n,m,du[MaxN],p;
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	cin >> n >> p; m = n;
	Fill(h,tot = 0);
	For(i,1,m) {
			int b,e;
		scanf("%d%d",&b,&e);
		add(b,e);
		++du[b], ++du[e];
	}
	int BIG = 300000;
	Fill(tree,0);
	For(i,1,n) ins(BIG - du[i],1);
	long long ans = 0;
	For(i,1,n) {
		ins(BIG - du[i],-1);
		map<int,int> MAP;
		for (int z = h[i]; z; z = next[z]) {
			++MAP[v[z]];
		}
		for (map<int,int> :: iterator it = MAP.begin(); it != MAP.end(); ++it) {
			if (du[i] + du[it->FI] - it->SE >= p) ++ans;
			ins(BIG - du[it->FI],-1);
		}
		ans += ask(BIG - (p - du[i]));
		for (map<int,int> :: iterator it = MAP.begin(); it != MAP.end(); ++it) {
			//if (du[i] + du[it->FI] - it->SE >= p) ++ans;
			ins(BIG - du[it->FI],1);
		}
		ins(BIG - du[i],1);
	}
	cout << ans / 2 << endl;
	return 0;
}
