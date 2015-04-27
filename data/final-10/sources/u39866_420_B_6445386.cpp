#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;
const int MAXN = 100005;
bool occur[MAXN];
bool flag[MAXN];
bool ans[MAXN];
int A[MAXN];
set<int > SS;
set<int > NE;
set<int >::iterator it;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) ans[i] = true;
	rep(i,1,m+1) {
		char ch[3],w;
		int x;
		scanf("%s%d",ch,&x);
		A[i] = x;
		if(ch[0] == '-') {
			if(!occur[x]) {
				for(int j = i-1; j && !flag[j]; j--) {
					flag[j] = true;
					ans[A[j]] = false;
				}
			} else {
				SS.erase(x);
				
			}
			if(SS.size()) {
				ans[x] = false;
				NE.erase(x);
			}
			if(ans[x]) NE.insert(x);
		} else {
			// printf("%d %d %d\n",x,occur[x], SS.size());
			if(!occur[x] && i > 1) ans[x] = false;
			if(SS.size()) {
				ans[x] = false;
				NE.erase(x);
			}
			SS.insert(x);
			NE.erase(x);
			for(it = NE.begin(); it != NE.end(); it++) {
				ans[*it] = false;
			}
			NE.clear();

		}
		occur[x] = true;
	}

	int cnt = 0;
	rep(i,1,n+1) if(ans[i]) cnt++;
	P(cnt);
	rep(i,1,n+1) if(ans[i]) printf("%d ",i);
	printf("\n");
	return 0;
}