#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct item
{
	int h, t, cnt;
	item(int _h, int _t, int _cnt)
	{
		h = _h;
		t = _t;
		cnt = _cnt;
	}
};

const int MAX_N = 1000, inf = 1000 * 1000 * 1000;
int f[MAX_N][MAX_N], A[MAX_N][2], B[MAX_N][2];
bool used[MAX_N][MAX_N], used1[MAX_N][MAX_N];
int n, m, R;
bool _draw = 0, b_iv = 0;
int _iv = inf, _zm = 0;
vector <item> Q;

int find(int h, int t, int cnt)
{
	int s = 0;
	Q.push_back(item(h, t, cnt));
	
	while (s < Q.size())
	{
	
	int h = Q[s].h, t = Q[s].t, cnt = Q[s].cnt;
	++s;
	
	if (h + t > R)
	{
	//	f[h][t] = 2 + 1;
		_zm = max(_zm, cnt);
		//return 2;
		continue;
	}
	
	if (h + t == 0)
	{
		_iv = min(_iv, cnt);
		b_iv = 1;
		continue;
	}

	if (used[h][t])
	{
	//	_draw = 1;
		continue;
	}
		
	used[h][t] = 1;
	
	for (int i = 1; i <= min(h, n); ++i)
		Q.push_back(item(h - i + A[i][0], t + A[i][1], cnt + 1));
	for (int i = 1; i <= min(t, m); ++i)
		Q.push_back(item(h + B[i][0], t - i + B[i][1], cnt + 1));
	}
}

int find1(int h, int t, int cnt)
{
	if (h + t > R)
		return 1;
		
	if (f[h][t])
		return f[h][t] - 1;
	if (used1[h][t])
	{
		_draw = 1;
		return 0;
	}
	used1[h][t] = 1;
	int _res = 0;
	for (int i = 1; i <= min(h, n); ++i)
	{
		int res = find1(h - i + A[i][0], t + A[i][1], cnt + 1);
		_res = max(_res, res);
	}
	for (int i = 1; i <= min(t, m); ++i)
	{
		int res = find1(h + B[i][0], t - i + B[i][1], cnt + 1);
		_res = max(_res, res);
	}
	
	f[h][t] = _res + 1;
	if (!_res)
		return 0;
	else
	{
		++f[h][t];
		return _res + 1;
	}
	
}

int main()
{
	int h, t;
	cin >> h >> t >> R;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> A[i][0] >> A[i][1];
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> B[i][0] >> B[i][1];
	
	find(h, t, 0);
	int res = find1(h, t, 0);
	/*if (!res)
		cout << "Draw";
	else if (res == 1)
		cout << "Ivan" << endl << _iv;
	else
		cout << "Zmey" << endl << _zm;
		*/
	if (b_iv)
		cout << "Ivan" << endl << _iv;
	else
		if (_draw)
			cout << "Draw";
		else
			cout << "Zmey" << endl << max(res - 1, _zm);	
	return 0;
}
