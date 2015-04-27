#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int dx[] = {0, 0, 1, 1};
const int dy[] = {0, 1, 0, 1};

int res = 0;
vector <int> ans;
vector <pair <int, int> > sq, can;
vector <pair <pair <int, int>, pair <int, int> > > d;
vector <int> now;
int b[40][40];

void Check()
{
	for(int i = 0; i < 14; i++)
		for(int k = 0; k < 4; k++)
			b[sq[i].first + dx[k]][sq[i].second + dy[k]] = now[i];
	vector <pair <int, int> > t;
	for(int i = 0; i < d.size(); i++)
		t.push_back(make_pair(b[d[i].first.first][d[i].first.second], b[d[i].second.first][d[i].second.second]));
	for(int i = 0; i < t.size(); i++)
		if(t[i].first > t[i].second)
			swap(t[i].first, t[i].second);
	sort(t.begin(), t.end());
	if(t == can)
	{
		res++;
		if(ans.empty())
			ans = now;
	}
}

void Func(int n)
{
	if(n == 7)
	{
		Check();
		return;
	}
	int beg = 0;
	for(int i = 0; i < 14; i++)
		if(now[i] == -1)
		{
			now[i] = n;
			beg = i;
			break;
		}
	for(int i = beg; i < 14; i++)
		if(now[i] == -1)
		{
			now[i] = n;
			Func(n + 1);
			now[i] = -1;
		}
	now[beg] = -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector <string> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(isalpha(arr[i][j]))
			{
				if(i + 1 < n && arr[i][j] == arr[i + 1][j])
					d.push_back(make_pair(make_pair(i, j), make_pair(i + 1, j)));
				if(j + 1 < m && arr[i][j] == arr[i][j + 1])
					d.push_back(make_pair(make_pair(i, j), make_pair(i, j + 1)));
			}
	vector <vector <bool> > was(n, vector <bool> (m, false));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!was[i][j] && isalpha(arr[i][j]))
			{
				for(int k = 0; k < 4; k++)
					was[i + dx[k]][j + dy[k]] = true;
				sq.push_back(make_pair(i, j));
			}
	now.assign(14, -1);
	for(int i = 0; i < 7; i++)
		for(int j = i; j < 7; j++)
			can.push_back(make_pair(i, j));
	Func(0);
	cout << (long long)res * 5040 << endl;
	vector <string> p(n, string(m, '.'));
	for(int i = 0; i < sq.size(); i++)
		for(int k = 0; k < 4; k++)
			p[sq[i].first + dx[k]][sq[i].second + dy[k]] = '0' + ans[i];
	for(int i = 0; i < n; i++)
		cout << p[i] << endl;
	return 0;
}