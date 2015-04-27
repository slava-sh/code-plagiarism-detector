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

#define NN 110000

int sum[NN], out[NN], last[NN];
int cnt, ans[NN], pre[NN];
int op[NN], id[NN], vst[NN];

int main() {
	
	int tot, cur, i, u, N, M;
	char ch;
	
	scanf("%d%d", &N, &M);
	
	memset(last, -1, sizeof(last)); tot=0;
	cur=0;
	for (i=0; i<M; i++) {
		scanf(" %c %d", &ch, &u); u--;
		if (ch=='+') op[i]=1;
		else op[i]=0;
		id[i]=u;
		pre[u]=1;
		if (!vst[u] && op[i]==0) cur++;
		vst[u]=1;
	}
	
	if (cur) tot++;
	for (i=0; i<M; i++) {
		u=id[i];
		if (op[i]) {
			cur++; last[u]=i;
			out[u]=0;
		} else {
			cur--;
			sum[u]+=i-last[u];
			out[u]=1;
		}
//		printf("%d %d\n", i, cur);
		if (cur) tot++;
	}
	
//	printf("%d\n", tot);
	int k=0;
	for (i=0; i<N; i++) 
		if (!out[i]) sum[i]+=M-last[i], k=1;
	
//	tot+=k;
	
	cnt=0;
	for (i=0; i<N; i++) {
//		printf("%d %d\n", i, sum[i]);
		if (!vst[i] || sum[i]==tot) ans[cnt++]=i;
	}
	
	printf("%d\n", cnt);
	for (i=0;i<cnt; i++) printf("%d%c", ans[i]+1, i==cnt-1?'\n':' ');
	
	return 0;
}

