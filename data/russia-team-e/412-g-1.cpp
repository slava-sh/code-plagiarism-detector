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

int main(void) {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1) {
		cout << (m + 1) / 4 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	return 0;
}