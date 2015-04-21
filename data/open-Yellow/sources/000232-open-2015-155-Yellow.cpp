#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

vector<int> t;

int n, q;

int get_cnt(int p)
{
	int cnt = 0;
	if (p - 1 >= 0)
		if (t[p - 1] != t[p])
			++cnt;
	if (p + 1 < n && t[p + 1] != t[p])
		++cnt;
	return cnt;
}

int main()
{
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	int ans = 1;
	for (int i = 1; i < n; ++i)
		if (t[i] != t[i - 1])
			++ans;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int p, c;
		scanf("%d%d", &p, &c);
		--p;
		ans -= get_cnt(p);
		t[p] = c;
		ans += get_cnt(p);
		printf("%d\n", ans);
	}
}