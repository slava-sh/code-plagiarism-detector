#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <ctime>
#include <bitset>
#include <ctype.h>
#include <complex>
#include <cassert>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template<class T> inline void chkmin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void chkmax(T &a, T b) { if (a<b) a=b; }

typedef long long INT;
typedef pair<int, int> pii;

#define NN 310000

int cnt[NN], num[NN];
map<pii, int> mp;
map<pii, int>::iterator it;

int main() {
	
	int N, M, i, u, v, mx;
	INT ans;
	scanf("%d%d", &N, &M);
	for (i=0; i<N; i++) {
		scanf("%d%d", &u, &v);
		u--, v--;
		if (u>v) swap(u, v);
		cnt[u]++, cnt[v]++;
		mp[pii(u, v)]++;
	}
	
	ans=mx=0;
	for (it=mp.begin(); it!=mp.end(); it++) {
		u=it->first.first;
		v=it->first.second;
//		printf("%d %d %d %d %d\n", u, v, cnt[u], cnt[v], it->second);
		if (cnt[u]+cnt[v]-it->second<M && cnt[u]+cnt[v]>=M) mx++;
	}
//	printf("%d\n", mx);
	
	for (i=0; i<N; i++) num[cnt[i]]++;
	for (i=N-1; i>=0; i--) num[i]+=num[i+1];
	
	INT tmp=0;
	for (i=0; i<N; i++) {
		int k=max(M-cnt[i], 0); 
		if (cnt[i]*2>=M) tmp--;
		tmp+=num[k];
	}
	tmp/=2; ans+=tmp;
	
	ans-=mx;
	
	printf("%I64d\n", ans);
	
	return 0;
}

