#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAXN = 10000;

int n;
int x[MAXN], y[MAXN], xt[MAXN], yt[MAXN];
set<pair<int, int> > result;

void read_data()
{
	scanf("%d", &n);

	for (int i = 0 ; i < n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		result.insert(make_pair(x[i], y[i]));
	}
}

void run(vector<int> &pid)
{
	if (pid.size() <= 1) return;

	int nt = pid.size();

	// ---------------------------------
	vector<pair<int, int> > coordsx(nt);

	for (int i = 0; i < nt; ++i) coordsx[i] = make_pair(x[pid[i]], pid[i]);
	sort(coordsx.begin(), coordsx.end());

	int nlx = 0, nrx = 0, sepx = coordsx[nt/2].first;
	for (int i = 0; i < nt; ++i) if (coordsx[i].first < sepx) ++nlx; else { if (coordsx[i].first > sepx) ++nrx; }

	// ---------------------------------
	vector<pair<int, int> > coordsy(nt);

	for (int i = 0; i < nt; ++i) coordsy[i] = make_pair(y[pid[i]], pid[i]);
	sort(coordsy.begin(), coordsy.end());

	int nly = 0, nry = 0, sepy = coordsy[nt/2].first;
	for (int i = 0; i < nt; ++i) if (coordsy[i].first < sepy) ++nly; else { if (coordsy[i].first > sepy) ++nry; }

	if (max(nlx, nrx) < max(nly, nry))
	{
		for (int i = 0; i < nt; ++i) result.insert(make_pair(sepx, y[pid[i]]));

		vector<int> lx; lx.reserve(nlx);
		for (int i = 0; i < nt; ++i) if (coordsx[i].first < sepx) lx.push_back(coordsx[i].second);

		vector<int> rx; rx.reserve(nrx);
		for (int i = 0; i < nt; ++i) if (coordsx[i].first > sepx) rx.push_back(coordsx[i].second);

		run(lx); run(rx);
	}
	else
	{
		for (int i = 0; i < nt; ++i) result.insert(make_pair(x[pid[i]], sepy));

		vector<int> ly; ly.reserve(nly);
		for (int i = 0; i < nt; ++i) if (coordsy[i].first < sepy) ly.push_back(coordsy[i].second);

		vector<int> ry; ry.reserve(nry);
		for (int i = 0; i < nt; ++i) if (coordsy[i].first > sepy) ry.push_back(coordsy[i].second);

		run(ly); run(ry);
	}
}

void solve()
{
	vector<int> pid; pid.reserve(n);
	for (int i = 0; i < n; ++i) pid.push_back(i);

	run(pid);

	printf("%d\n", result.size());

	for (set<pair<int, int> >::iterator q = result.begin(); q != result.end(); ++q)
	{
		printf("%d %d\n", q->first, q->second);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	read_data();
	solve();

	return 0;
}
