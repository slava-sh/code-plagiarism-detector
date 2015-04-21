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

int get_ans(int i1, int i2)
{
	return (abs(h[i1] - i1) + abs(i2 - h[i2]) - abs(h[i2] - i1) - abs(h[i1] - i2));
}

int main()
{
	int n;
	cin >> n;
	h.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		--h[i];
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
	int imax1 = 0;
	for (int i = 0; i < n; ++i)
		if (i - h[i] >= imax1 - h[imax1])
			imax1 = i;
	int i1 = 0;
	if (i1 == imax1)
		++i1;
	int ans1 = get_ans(min(i1, imax1), max(i1, imax1));
	int i21 = 0, i22 = n - 1;
	int ans2 = get_ans(0, n - 1);
	int imax3 = 0, imin3 = 0;
	for (int i = 0; i < n; ++i)
		if (h[i] > h[imax3])
			imax3 = i;
		else if (h[i] < h[imin3])
			imin3 = i;
	int ans3 = get_ans(min(imin3, imax3), max(imin3, imax3));
	int imax4 = 0;
	for (int i = 0; i < n; ++i)
		if (h[i] - i > h[imax4] - imax4)
			imax4 = i;
	int imin4 = 0;
	if (imin4 == imax4)
		++imin4;
	for (int i = 0; i < n; ++i)
		if (i != imax4)
			if (h[i] < h[imin4])
				imin4 = i;
	int ans4 = get_ans(min(imin4, imax4), max(imin4, imax4));
	if (ans1 > ans2 && ans1 > ans3 && ans1 > ans4)
	{
		cout << min(i1, imax1) + 1 << ' ' << max(i1, imax1) + 1 << endl;
	}
	else if (ans2 > ans3 && ans2 > ans4)
	{
		cout << 1 << ' ' << n << endl;
	}
	else if (ans3 > ans4)
	{
		cout << min(imin3, imax3) + 1 << ' ' << max(imin3, imax3) + 1 << endl;
	}
	else
	{
		cout << min(imin4, imax4) + 1 << ' ' << max(imin4, imax4) + 1 << endl;
	}
}