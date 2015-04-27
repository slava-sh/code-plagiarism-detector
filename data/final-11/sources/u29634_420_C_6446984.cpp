#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

const int N = 300005;

int n, p, x[N], y[N], cnt[N];

int main() {
	scanf("%d%d", &n, &p);
	map<PII,int> mp;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x+i, y+i);
		if (x[i] > y[i]) swap(x[i], y[i]);
		cnt[--x[i]]++;
		cnt[--y[i]]++;
		mp[PII(x[i], y[i])]++;
	}
	LL ans = 0, fake = 0;
	for (map<PII,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		int xi = it->first.first;
		int yi = it->first.second;
		int ci = it->second;
		if (cnt[xi] + cnt[yi] - ci >= p) ;
		else if (cnt[xi] + cnt[yi] >= p) ++fake;
	}
	sort(cnt, cnt+n);
	LL pd2 = 0;
	for (int i = 0; i < n; ++i) {
		int k = lower_bound(cnt, cnt + n, p - cnt[i]) - cnt;
		if (k <= i) k = i + 1;
		ans += n - k;
//		printf("k = %d\n", k);
	}
	ans -= fake;
	printf("%I64d\n", ans);
}