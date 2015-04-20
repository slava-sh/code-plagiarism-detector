#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#pragma comment (linker, "/STACK:136667216")

using namespace std;

struct Ev
{
	int x;
	int t;
};

bool operator <(Ev a, Ev b)
{
	return a.x < b.x || a.x == b.x && a.t > b.t;
}
long long pref[200001];
int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	vector <Ev> a;
	long long h, n;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> pref[i + 1];
	for (int i = 1; i <= n; i++)
	{
		Ev q;
		if (pref[i] > h) continue;
		q.x = i - h; //q.x - index
		q.t = 1;
		a.push_back(q);
		q.x += h - pref[i]; //index diff
		q.x = min(q.x, i);
		q.t = -1;
		a.push_back(q);
	}
	sort(a.begin(), a.end());
	long long thing = h * (h + 1) / 2;
	for (int i = 1; i <= n; i++) pref[i] = pref[i] + pref[i - 1];
	int cur = 0;
	long long best = 1LL << 50;
	for (auto it = a.begin(); it != a.end(); it++)
	{
		cur += it->t;
		if (cur == h)
			best = min(best, thing - pref[it->x + h] + pref[it->x]);
	}
	if (best == 1LL << 50) cout << -1;
	else cout << best;
	return 0;
}