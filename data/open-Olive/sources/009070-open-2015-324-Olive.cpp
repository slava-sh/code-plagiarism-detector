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
//#include <tuple>
//#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

#define ll int

using namespace std;

const int MAXN = 15e3 + 10;
const int INF = 2e9;

int a[MAXN];
short int d[MAXN][MAXN];
short int c[MAXN][MAXN];
int n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int best = 0;
	pair<int, int> best_pos = make_pair(-2, -2);
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		ll csum = 0;
		d[i][i] = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) sum++;
			else csum++;
			d[i][j] = sum;
			c[i][j] = csum;
		}
		sum = 0;
		csum = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > a[i]) sum++;
			else csum++;
			d[i][j] = sum;
			c[i][j] = csum;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int diff = d[i][j] + d[j][i] - c[i][j] - c[j][i] + 1 * (((a[i] < a[j]) != (i < j)) ? -1 : 1);
			if (diff > best && i != j) {
				best = diff;
				best_pos = make_pair(i, j);
			}
		}
	}
	
	cout << best_pos.first + 1 << ' ' << best_pos.second + 1<< '\n';
		
	return 0;
}
