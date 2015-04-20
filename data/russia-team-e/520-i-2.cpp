#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector <int> a;
vector <int> maxi;

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t < 3 * d && t > 2 * d) {
			maxi.push_back(t);
		}
		else if (t >= 3 * d) {
			a.push_back(t);
		}
	}
	sort(maxi.begin(), maxi.end());
	if (a.size() == 1 && maxi.size() == 0) {
		cout << a[0] << endl;
		return 0;
	}
	if (a.size() == 0 && maxi.size() == 0) {
		cout << "0\n";
		return 0;
	}
	if (a.size() == 0 && maxi.size() == 1) {
		cout << maxi[0] << "\n";
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] - 2 * d;
	}
	int kol = 0;
	int i = (int)maxi.size() - 1;
	while (kol < 2 && i >= 0) {
		ans += maxi[i] - d;
		kol++;
		i--;
	}
	ans += d * (2 - kol);
	cout << ans;
}