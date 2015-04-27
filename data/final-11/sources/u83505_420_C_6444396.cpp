#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef pair < int, int > pii;
typedef long long ll;
const int MAX = 300020;

int n, m, check[MAX], f[MAX], s[MAX];
vector < int > from[MAX];

void input(){
	scanf("%d%d", &n, &m);

	int i;
	for(i = 1; i<=n; i++){
		scanf("%d%d", &f[i], &s[i]);

		from[f[i]].push_back(i);
		from[s[i]].push_back(i);

		check[f[i]]++;
		check[s[i]]++;
	}
}

int list[MAX];

void solve(){
	ll res = 0;

	int i;
	for(i = 0; i<n; i++)
		list[i] = check[i+1];

	sort(list, list+n);

	for(i = 1; i<=n; i++){
		int remain = m-check[i];

		int maybe = n-(lower_bound(list, list+n, remain)-list);
		if(check[i] >= m-check[i]) maybe--;

		int j;
		for(j = 0; j<from[i].size(); j++){
			int now = from[i][j];
			int other = f[now]+s[now]-i;
			if(check[other] == remain) maybe--;
			check[other]--;
		}

		for(j = 0; j<from[i].size(); j++){
			int now = from[i][j];
			int other = f[now]+s[now]-i;
			check[other]++;
		}

		res += maybe;
	}

	printf("%I64d\n", res>>1);
}

int main(){
	input();

	solve();

	return 0;
}