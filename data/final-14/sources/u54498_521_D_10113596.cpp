#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#define mp make_pair
using namespace std;

int k, n, m, t, j, b, p1[110000], p2[110000], qq[110000], anst, mm[110000], ss[110000];
long long a[110000];
long double d[110000], dd[110000], ans, ans1;
vector <pair<int, int> > V, ve1[110000];
set <pair<long double, int> > Set;
vector <int> V2;

int main() {
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= k; i++) {
		scanf("%I64d", &a[i]);
		d[i] = logl(a[i]);
		ans += d[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &t, &j, &b);
		ss[i] = b;
		if (t == 1) {
			mm[i] = 1;
			if (b > p1[j]) {
				p1[j] = b;
				p2[j] = i;
				ss[i] -= a[j];
			}
		}else if (t == 2) {
			ve1[j].push_back(mp(b, i));
		}else V.push_back(mp(b, i));
	}
	for (int i = 1; i <= k; i++) {
		if (p2[i])
			ve1[i].push_back(mp(p1[i] - a[i], p2[i]));
		sort(ve1[i].rbegin(), ve1[i].rend());
		qq[i] = 1;
	}
	sort(V.rbegin(), V.rend());
	int L = V.size();
	for (int i = 1; i <= L; i++)
		dd[i] = dd[i - 1] + logl(V[i - 1].first);
	for (int i = 1; i <= k; i++) {
		if (qq[i] <= (int) ve1[i].size()) Set.insert(mp(logl(ve1[i][qq[i] - 1].first + a[i]) - d[i], i));
	}
	anst = 0;
	ans = dd[min(L, m)];
	int ll = 0;
	while (!Set.empty() && ll < m) {
		pair<long double, int> t = *Set.rbegin();
		Set.erase(*Set.rbegin());
		ll++;
		V2.push_back(ve1[t.second][qq[t.second] - 1].second);
		
		d[t.second] += t.first;
		a[t.second] += ss[ve1[t.second][qq[t.second] - 1].second];
		qq[t.second]++;
		ans1 += t.first;
		if (qq[t.second] <= (int) ve1[t.second].size()) Set.insert(mp(logl(ve1[t.second][qq[t.second] - 1].first + a[t.second]) - d[t.second], t.second));
		if (ans1 + dd[min(L, m - ll)] > ans) {
			ans = ans1 + dd[min(L, m - ll)];
			anst = ll;
		}
	}
	printf("%d\n", anst + min(L, m - anst));

	for (int i = 0; i < anst; i++)
		if (mm[V2[i]]) printf("%d ", V2[i]);
	for (int i = 0; i < anst; i++)
		if (!mm[V2[i]])	printf("%d ", V2[i]);
	for (int i = 0; i < min(L, m - anst); i++)
		printf("%d ", V[i].second);
}
