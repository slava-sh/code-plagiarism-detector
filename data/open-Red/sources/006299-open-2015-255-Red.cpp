#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <time.h>
using namespace std;

#define lint long long int
#define C 50005

struct node
{
	int cur;
	int lt;
	bool first;
	int time;
};

bool operator<(node a, node b)
{
	return a.cur < b.cur || a.cur == b.cur && a.lt < b.lt;
}

int abs0(int x)
{
	if(x < 0)
		return -x;
	return x;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, M, D;
	cin >> N >> M >> D;

	int lvl[C];
	vector<vector<pair<int, int>>> v0;
	
	for(int i = 0 ; i <= N + 5; i++)
	{
		vector<pair<int, int>> new0;
		v0.push_back(new0);
	}
	for(int i = 0; i < M; i++)
	{
		int u, z, t;
		cin >> u >> z >> t;
		v0[u].push_back(make_pair(z, t));
		v0[z].push_back(make_pair(u, t));
	}
	int Q;
	cin >> Q;
	queue<node> bfs;
	node x;
	x.first = 1;
	x.time = 0;
	for(int k = 0; k < Q; k++)
	{
		//for(int i = 0; i < N; i++)
		//lvl[i] = -1;

		int A, B;
		cin >> A >> B;
		x.cur = A;
		bfs.push(x);

		map<node, bool> been;
		been[x] = 1;

		int cnt = 0;

		bool found = 0;
		
		while(bfs.empty() == 0)
		{
			cnt++;
			if(clock() > CLOCKS_PER_SEC * 3.5)
				break;
			node cur = bfs.front();
			int curV = cur.cur;
			if(curV == B)
			{
				found = 1;
				cout << cur.time << endl;
				break;
			}
			for(int i = 0; i < v0[curV].size(); i++)
			{
				bool good = 0;
				if(v0[curV][i].first == A)
					continue;
				if(1)//lvl[v0[curV][i].first] < k)
				{
					if(cur.first)
					{
						good = 1;
					}else if(abs0(cur.lt - v0[curV][i].second) <= D)
					{
						good = 1;
					}
				}
				if(good)
				{
					node n;
					n.first = 0;
					n.lt = v0[curV][i].second;
					n.cur = v0[curV][i].first;
					n.time = cur.time + 1;

					if(been[n] == 0)
					bfs.push(n);
					been[n] = 1;
					//lvl[n.cur] = k;
				}
			}
			bfs.pop();
		}
		while(bfs.empty() == 0)
			bfs.pop();
		if(found == 0)
			cout << -1 << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}