#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:256000000");
using namespace std;

int n, m, t;
set<pair<int, int> > q;
long long hf()
{
	long long h = 0;
	for (set<pair<int, int>>::iterator i = q.begin(); i != q.end(); i++)
	{
		h = (h * 101 * 101 + 101 * i->first + i->second) % 999999999997;
	}
	return h;

}

map<long long, long long> a;

long long dfs(int t)
{
	long long h = hf();
	if (t == 0)
	{
		if (a.find(h) == a.end())
		{
			a[h] = 1;
			return 1;
		}
		else
			return 0;
	}
	
	if (a.find(h) == a.end())
	{
		long long ans = 0;
		for (set<pair<int, int>>::iterator i = q.begin(); i != q.end(); i++)
		{
			int x = i->first;
			int y = i->second;
			if (x - 1 >= 0 && q.find(make_pair(x - 1, y)) == q.end())
			{
				q.insert(make_pair(x - 1, y));
				ans += dfs(t - 1);
				q.erase(q.find(make_pair(x - 1, y)));
			}
			if (x + 1 < n && q.find(make_pair(x + 1, y)) == q.end())
			{
				q.insert(make_pair(x + 1, y));
				ans += dfs(t - 1);
				q.erase(q.find(make_pair(x + 1, y)));
			}
			if (y - 1 >= 0 && q.find(make_pair(x, y - 1)) == q.end())
			{
				q.insert(make_pair(x, y - 1));
				ans += dfs(t - 1);
				q.erase(q.find(make_pair(x, y - 1)));
			}
			if (y + 1 < m && q.find(make_pair(x, y + 1)) == q.end())
			{
				q.insert(make_pair(x, y + 1));
				ans += dfs(t - 1);
				q.erase(q.find(make_pair(x, y + 1)));
			}
		}
		a[h] = ans;
		return ans;
	}
	return 0;
}





vector<pair<long long, long long>> b[1000000];
int p[1000000];

int main()
{
	freopen("virus.in", "r", stdin);
	freopen("virus.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '*')
				q.insert(make_pair(i, j));
		}
	cout << dfs(t);
	
	return 0;
}