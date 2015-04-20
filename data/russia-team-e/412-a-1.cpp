#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#include<queue>
#include<string>
#include<map>

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define next next_asjkdh
using namespace  std;

const int inf = (int)1e+9 + 7;

int main(void) {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> z(n);
	vector <int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> z[i];
		if (!(i + z[i] - 1 < n)) {
			cout << "0\n";
			return 0;
		}
	}
	int an = 2;
	ans[0] = 1;

		for (int i = 0; i < n; ++i) {
				if (z[i] == -1)
					continue;
				if (i + z[i] < ans.size() && z[i] == 0)
					ans[i + z[i]] = 0;
				if (0 < z[i])
					ans[i + 0] = 1;
			}

	/*for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << "\n";*/

	for (int x = 1; x < n; ++x) {
		bool one = false, zero = false;
		if (ans[x] == -1) {
			zero = true;
			one = true;
		} else {
			if (ans[x] == 0)
				zero = true;
			else
				one = true;
		}

			ans[x] = 1;
			for (int i = 0; i < n; ++i) {
				if (z[i] == -1)
					continue;
				if (i + z[i] < ans.size() && ans[i + z[i]] == 1 && z[i] == x)
					one = false;
				if (x < z[i] && ans[i + x] == 0)
					one = false;
			}

			ans[x] = 0;
			for (int i = 0; i < n; ++i) {
				if (z[i] == -1)
					continue;
				if (i + z[i] < ans.size() && ans[i + z[i]] == 0 && z[i] == x)
					zero = false;
				if (x < z[i] && ans[i + x] == 1)
					zero = false;
			}
		

		if (one && zero)
			an = (an * 2) % inf;

		if (!(one || zero)) {
			cout << "0\n";
			return 0;
		}

		if (one) {
			ans[x] = 1;
			for (int i = 0; i < n; ++i) {
				if (z[i] == -1)
					continue;
				if (i + z[i] < ans.size() && z[i] == x)
					ans[i + z[i]] = 0;
				if (x < z[i])
					ans[i + x] = 1;
			}
			continue;
		} else {
			ans[x] = 0;
			for (int i = 0; i < n; ++i) {
				if (z[i] == -1)
					continue;
				if (i + z[i] < ans.size() && z[i] == x)
					ans[i + z[i]] = 1;
				if (x < z[i])
					ans[i + x] = 0;
			}
		}
	}

	cout << an << endl;
}