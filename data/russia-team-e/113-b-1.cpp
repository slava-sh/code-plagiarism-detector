#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int n, x, r;
long long ans;
vector < int > d;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> r;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		d.push_back(x);
	}
	for (int i = 0; i < n; ++i)
		ans += n - (upper_bound(d.begin(), d.end(), d[i] + r) - d.begin());
	cout << ans << endl;
	//system("pause");
}