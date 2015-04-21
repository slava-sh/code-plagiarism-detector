#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <string>
#include <cstring>
#pragma comment(linker, "/STACK:100000000")
using namespace std;

const int MAXINT = 1000000010;
const long long MAXLL = 2e18;
const long long MODUL = 1000000007;



template <typename T>
inline T MIN(T a, T b)
{
	return (a < b ? a : b);
}

struct edge
{
	int wh, T; 
};

struct per
{
	int wh, ti, temp;
};

struct comp
{
	bool operator() (const edge& l, const edge& r)
	{
		return (r.T == l.T ? l.wh < r.wh : l.T < r.T);
	}
};

struct ver
{
	set<edge, comp> so;
	vector<edge> g;
};

int main()
{
	int n, m, d, q, a, b, ans;
	ver mas[100001];
	queue<per> go;
	set<edge, comp>::iterator it;
	edge te;
	per id, id1;
	scanf("%d%d%d", &n, &m, &d);
	++n;
	for(int i(0); i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &q);
		te.wh = b;
		te.T = q;
		mas[a].g.push_back(te);
		te.wh = a;
		mas[b].g.push_back(te);
	}
	scanf("%d", &q);
	while(q--)
	{
		ans = -1;
		scanf("%d%d", &a, &b);
		for(int i(1); i < n; ++i)
		{
			mas[i].so.clear();
			for(int j(0); j < mas[i].g.size(); ++j)
				mas[i].so.insert(mas[i].g[j]);
		}
		for(int i(0); i < mas[a].g.size(); ++i)
		{
			id.wh = mas[a].g[i].wh;
			id.ti = 1;
			id.temp = mas[a].g[i].T;
			go.push(id);
		}
		mas[a].so.clear();
		for(;go.size();go.pop())
		{
			id = go.front();
			if(id.wh == b)
			{
				ans = id.ti;
				break;
			}
			te.T = id.temp - d;
			te.wh = -1;
			while(1)
			{
				it = mas[id.wh].so.lower_bound(te);
				if(it == mas[id.wh].so.end() || it->T > id.temp + d)
					break;
				id1.wh = it->wh;
				id1.temp = it->T;
				id1.ti = id.ti + 1;
				go.push(id1);
				mas[id.wh].so.erase(it);
			}
		}
		for(;go.size();go.pop());
		printf("%d\n", ans);
	}
	return 0;
}














