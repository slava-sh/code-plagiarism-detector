#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>

using namespace std;

int n, m, a[300001], r, l, c, ans = 0;


int main()
{
	FILE *in, *out;
	in = freopen("che.in", "r", stdin);
	out = freopen("che.out", "w", stdout);
//-------------------------------------------------------------------

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		r = i;
		l = 0;
		while (r - l > 1) {
			c = (r + l) / 2;
			if (a[i] - a[c] > m) {
				l = c;
			}
			else
				r = c;
		}
		if (a[i] - a[l] > m)
			ans += l + 1;
	}
	cout << ans;
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
