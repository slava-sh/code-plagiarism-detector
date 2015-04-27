#pragma comment(linker, "/STACK:10000000")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
#include <string>
#include <cstring>
#define ldb long double
#define LL long long
#define fi first
#define se second
#define fill(a, c) memset(a, c, sizeof(a))
#define sqr(a) ((a) * (a))
#define nextLine() {int c = 0; while((c = getchar()) != 10 && c != EOF);}
#define getBit(mask, k) (((mask) / pw[k]) % pw[1])
#define setBit(mask, k, l) (((mask) / pw[k + 1] * pw[1] + (l)) * pw[k] + ((mask) % pw[k]))
#define debug(a) cerr << #a << " = " << a << " ";
#define debugl(a) cerr << #a << " = " << a << "\n";
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define ff first
#define ss second 
const ldb LDINF = 9128739847123.00;
const ldb eps = 1e-9;
const int inf = 1 << 28;
const ldb pi = fabsl(atan2l(0.0, -1.0));
using namespace std;


int n, a[123123];
map <int, int> cnt;
set <pair <int, int> > b;

void load()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (cnt[a[i]] > 0)
			b.erase(mp(-cnt[a[i]], a[i]));
		cnt[a[i]]++;
		b.insert(mp(-cnt[a[i]], a[i]));
	}
}

int was[123123];
vector <pair <int, pair <int , int> > > res;

void solve()
{
	/*int pos1 = 0, pos2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (was[i]) continue;
		while (pos1 < n && (a[pos1] <= a[i] || was[pos1])) pos1++;
		pos2 = max(pos2, pos1);
		while (pos2 < n && (a[pos2] <= a[pos1] || was[pos2])) pos2++;
		if (pos1 == n || pos2 == n) break;
		res.pb(mp(a[i], mp(a[pos1], a[pos2])));
		was[i] = was[pos1] = was[pos2] = 1;
	}
	*/
	set <pair <int, int> > :: iterator it;
	int c[3];
	while (b.size() >= 3)
	{
		it = b.begin();
		for (int i = 0; i < 3; i++)
		{
			c[i] = (*it).second;
			it++;
		}
		for (int i = 0; i < 3; i++)
		{
			b.erase(mp(-cnt[c[i]], c[i]));
			cnt[c[i]]--;
			if (cnt[c[i]] > 0)
				b.insert(mp(-cnt[c[i]], c[i]));
		}
		sort(c, c + 3);
		res.pb(mp(c[0], mp(c[1], c[2])));
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].ss.ss, res[i].ss.ff, res[i].ff);
}

#define file "c"
int main()
{
	#ifndef ONLINE_JUDGE
		freopen(file".in", "rt", stdin);
		freopen(file".out", "wt", stdout);
	#endif
	load();
	solve();
	return 0;
}
