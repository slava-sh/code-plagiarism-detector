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

bool cmp(int a, int b) {//a < b
	return (a > b);
}

int main(void) {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);
	int l = 0;
	int r = a[a.size() - 1] + 1;
	while (l < r - 1) {
		int x = (l + r) / 2;
		int to = k;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (to - a[i] < 0) {
				ok = false;
				break;
			}
			to -= x;
		}
		if (ok)
			l = x;
		else
			r = x;
	}
	cout << l << endl;
	return 0;
}