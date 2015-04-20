#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
    
using namespace std;

int n, m, s, f;
vector <int> q[200000];
int mx, sz;
vector <int> w;
int used[200000], rank[200000], need[200000], ww[200000];
int boo = 0;

void dfs(int v)
{
	if (boo == -1)
		return;	
	w.push_back(v);
	used[v] = 1;
    if (v == f)
	{
		boo = -1;
		for (int i = 0; i < (int)w.size(); i++)
			ww[i] = w[i];
		sz = (int)w.size();
		return;
	}
	for (int i = 0; i < (int)q[v].size(); i++)
		if (used[q[v][i]] == 0)
			dfs(q[v][i]);
	used[v] = 2;
	w.pop_back();
}   	


void dfsN(int v, int p) 
{
	used[v] = 1;
	for (int i = 0; i < (int)q[v].size(); i++)
		if (used[q[v][i]] == 0)
		{
			rank[q[v][i]] = rank[v] + 1;
			dfsN(q[v][i], p);
		}
	used[v] = 2;
	if (rank[v] > need[p])
		need[p] = rank[v];
}


int main()
{
    freopen("dwarfs.in", "r", stdin);
    freopen("dwarfs.out", "w", stdout);
    cin >> n;
	int a, b;
    for (int i = 0; i < n - 1; i++)
    {
    	cin >> a >> b;
		a--, b--;
		q[a].push_back(b);
		q[b].push_back(a);
    }

	cin >> s >> f;
	s--, f--;
	dfs(s);

	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < sz; i++)
		used[ww[i]] = 3;
	for (int i = 0; i < sz; i++)
	{
		//cout << ww[i] << " ";
		dfsN(ww[i], i);
		used[ww[i]] = 3;
        //cout << need[i] << endl;
	}
                
    rank[0] = need[0] + 1;
    mx = max(mx, min(rank[0], need[1] + sz - 1));
	for (int j = 1; j < sz - 1; j++)
	{
		rank[j] = max(rank[j - 1], need[j] + j + 1);
	    mx = max(mx, min(rank[j], need[j + 1] + sz - j - 1));
	}
	cout << mx;
	return 0;
}