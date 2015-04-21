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
	int i1 = 0, i2 = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (get_ans(i, j) > get_ans(i1, i2))
			{
				i1 = i;
				i2 = j;
			}
	cout << i1 + 1 << ' ' << i2 + 1 << endl;
}