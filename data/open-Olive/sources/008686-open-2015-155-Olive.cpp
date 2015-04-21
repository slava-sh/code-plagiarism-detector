#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

vector<int> h;

vector<int> cnt;

int s[5009][5009];


int get_ans(int i1, int i2)
{
	if (i2 < h[i2] || h[i1] < i1)
		return -1;
	int cnt1 = 0, cnt2 = 0;
	for (int i = i1 + 1; i <= i2; ++i)
		if (h[i] < h[i1])
			++cnt1;
		else
			++cnt2;
	for (int i = i1; i < i2; ++i)
		if (h[i] > h[i2])
			++cnt1;
		else
			++cnt2;
	return (cnt1 - cnt2);
}

int tr[4000009];

inline void Update(int v, int vl, int vr, int id)
{
	if (vl > id || vr <= id)
		return;
	if (vr - vl == 1)
	{
		tr[v] = cnt[vl];
		return;
	}
	Update(2 * v + 1, vl, (vl + vr) / 2, id);
	Update(2 * v + 2, (vl + vr) / 2, vr, id);
	tr[v] = tr[2 * v + 1] + tr[2 * v + 2];
}

inline int GetSum(int v, int vl, int vr, int l, int r)
{
	if (vl >= r || l >= vr)
		return 0;
	if (vl >= l && vr <= r)
		return tr[v];
	int ans1 = GetSum(2 * v + 1, vl, (vl + vr) / 2, l, r);
	int ans2 = GetSum(2 * v + 2, (vl + vr) / 2, vr, l, r);
	return ans1 + ans2;
}

int main()
{
	int n;
	cin >> n;
	h.resize(n);
	cnt.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		--h[i];
		if (i > 0)
			for (int j = 0; j < n; ++j)
				s[i][j] = s[i - 1][j];
		for (int j = h[i] + 1; j < n; ++j)
			s[i][j]++;
	}
	bool f = true;
	for (int i = 0; i < n; ++i)
		if (h[i] != i)
			f = false;
	if (f)
	{
		cout << -1 << ' ' << -1 << endl;
		return 0;
	}
	int i1 = 0, i2 = 0;
	int res = -1;
	/*for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (get_ans(i, j) > get_ans(i1, i2))
			{
				i1 = i;
				i2 = j;
			}*/
	for (int i = 0; i < n; ++i)
	{
		//cnt[h[i]]++;
		//Update(0, 0, n, h[i]);
		for (int j = 0; j < i; ++j)
		{
			if (h[j] > j && h[i] < i)
			{
				int cnt1 = 0, cnt2 = 0;
				//for (int t = h[j] - 1; t >= 0; --t)
					//cnt1 += cnt[t];
				//cnt1 += GetSum(0, 0, n, 0, h[j]);
				cnt1 += s[i][h[j]] - s[j][h[j]];
				cnt2 += i - j - cnt1;
				int c = 0;
				//for (int t = h[i] + 1; t < n; ++t)
					//c += cnt[t];
				//c += GetSum(0, 0, n, h[i] + 1, n);
				c += s[i][h[i]];
				if (j > 0)
					c -= s[j][h[i]];
				cnt1 += i - j - c;
				cnt2 += c;
				if (cnt1 - cnt2 > res)
				{
					res = cnt1 - cnt2;
					i1 = j;
					i2 = i;
				}
			}
			//cnt[h[j]]--;
			//Update(0, 0, n, h[j]);
		}
		/*for (int j = 0; j < i; ++j)
		{
			cnt[h[j]]++;
			Update(0, 0, n, h[j]);
		}*/
	}
	cout << i1 + 1 << ' ' << i2 + 1 << endl;
}