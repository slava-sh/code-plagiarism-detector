#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <list>
#include <bitset>
#include <cstring>
#include <string>
// C++11 Headers
#include <tuple>
#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

int n;
int a[MAXN];
int cnt = 0;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	a[0] = -INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
		if (a[i] != a[i + 1])
			cnt++;
	}
	a[n + 1] = -INF;
	debug("start ans %d\n", cnt);
	
	int m;
	cin >> m;
	for (int q =0; q < m; q++) {
		int pos, value;
		cin >> pos >> value;
		if (a[pos] == a[pos - 1] && value != a[pos - 1]) {
			cnt++;
			debug("<^");
		}
		if (a[pos] != a[pos - 1] && value == a[pos - 1]) {
			cnt--;
			debug("<v");
		}
		if (a[pos] == a[pos + 1] && value != a[pos + 1]) {
			cnt++;
			debug(">^");
		}
		if (a[pos] != a[pos + 1] && value == a[pos + 1]) {
			debug(">v");
			cnt--;
		}
		debug("\n");
		a[pos] = value;
		assert(cnt >= 1);
		cout << cnt << '\n';
	}
		
	return 0;
}
