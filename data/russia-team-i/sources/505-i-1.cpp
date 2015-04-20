#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 100005;

int a[MAX_N];
vector<int> v_3d, v_2d;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
#endif
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++)
		if (a[i] >= 3 * d)
			v_3d.push_back(a[i]);
		else if (a[i] >= 2 * d && a[i] < 3 * d)
			v_2d.push_back(a[i]);

	int ans = 0;
	for (int i = 0; i < (int)v_3d.size(); i++)
		ans += v_3d[i];

	ans -= 2 * d * (max((int)v_3d.size() - 1, 0));
	if ((int)v_2d.size() > 0)
		ans += v_2d[(int)v_2d.size() - 1] - 2 * d;
	if ((int)v_2d.size() > 1)
		ans += v_2d[(int)v_2d.size() - 2] - 2 * d;

	if (ans == 0)
		ans = a[n - 1];

	cout << ans;

	return 0;
}