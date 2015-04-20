#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define FNAME "secure"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int n, m, d[5001], ans = 1e9, v, ans1 = 1e9, res, res1, b[5001], x, y, z;
vector <pair<int, int> > a[5001];
set <pair <int, int> > s;
int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &b[i]);
	forn(i, m)
	{
		scanf("%d%d%d", &x ,&y, &z);
		x--, y--;
		a[x].pb(mp(y, z));
		a[y].pb(mp(x, z));
	}
	forn(i, n)
		d[i] = 1e9;
	forn(i, n)
	{
		if (b[i] == 1)
			d[i] = 0;	
		s.insert(mp(d[i], i));
	}
	while (s.size())
	{
		v = s.begin()->second;
		s.erase(s.begin());
		forn(i, (int) a[v].size())
		{
			if (d[v] + a[v][i].second < d[a[v][i].first])
			{
				s.erase(mp(d[a[v][i].first], a[v][i].first));
				d[a[v][i].first] = d[v] + a[v][i].second;
		    	s.insert(mp(d[a[v][i].first], a[v][i].first));
			}
		}
			
	}

	forn(i, n)
	{
	//	printf("%d ", d[i]);
		if (b[i] == 2)
		{
			if (ans > d[i])
			{
				ans = d[i];
				res = i;
			}
		}
	}
		
	if (ans == 1e9)
	{
		puts("-1");
		return 0;
	}
	forn(i, n)
		d[i] = 1e9;
	forn(i, n)
	{
		if (i == res)
			d[i] = 0;	
		s.insert(mp(d[i], i));
	}
	while (s.size())
	{
		v = s.begin()->second;
		s.erase(s.begin());
		forn(i, (int) a[v].size())
		{
			if (d[v] + a[v][i].second < d[a[v][i].first])
			{
				s.erase(mp(d[a[v][i].first], a[v][i].first));
				d[a[v][i].first] = d[v] + a[v][i].second;
		    	s.insert(mp(d[a[v][i].first], a[v][i].first));
			}
		}
			
	}         
	forn(i, n)
	{
	
		if (b[i] == 1)
		{
			if (ans1 > d[i])
			{
				ans1 = d[i];
				res1 = i;
			}
		}
	}
	printf("%d %d %d\n", res1 + 1, res + 1, ans); 
	return 0;
}