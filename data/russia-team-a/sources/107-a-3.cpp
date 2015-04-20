#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool w[1001];
int res = 1;
int tp[1001];
vector <int> e1[1001];
vector <int> e2[1001];
const int MODULE = 1000000007;

void dfs(int v)
{
	for (int i = 0; i < e1[v].size(); i++)
	{
		if (tp[e1[v][i]] == 1 - tp[v]) res = 0;
		else if (tp[e1[v][i]] == -1) 
		{
			tp[e1[v][i]] = tp[v];
			dfs(e1[v][i]);
		}
	}
	for (int i = 0; i < e2[v].size(); i++)
	{
		if (tp[e2[v][i]] == tp[v]) res = 0;
		else if (tp[e2[v][i]] == -1)
		{
			tp[e2[v][i]] = 1 - tp[v];
			dfs(e2[v][i]);
		}
	}
}

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		tp[i] = -1;
		int x;
		cin >> x;
		if (x > (n - i))
		{
			cout << 0 << endl;
			return 0;
		}
		if (i == 0)
		{
			if (x > 0)
			{
				cout << 0 << endl;
		    	return 0;
			}
			continue;
		}
		if (x == -1) continue;
		for (int j = 0; j < x; j++)
		{
			e1[j].push_back(i + j);
			e1[i + j].push_back(j);
		}
		if (x == n - i) continue;
		e2[i + x].push_back(x);
		e2[x].push_back(i + x);
	}
	for (int i = 0; i < n; i++)
	{
		if (tp[i] == -1)
		{
			tp[i] = 0;
			res *= 2;
			res = res % MODULE;
			dfs(i);
		}
	}
	cout << res << endl;
	return 0;
}