#include <cstdio>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cmath>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define X first
#define Y second
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))
 
template<typename T> T sqr(const T &x) {
    return x * x;
}
 
template<typename T> T my_abs(const T &x) {
    return x < 0 ? -x : x;
}
 
typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld,ld> pd;
 
const int INF = (int)1e9;
const li LINF = (li)4e18;
const ld EPS = 1e-9;
const li MOD = (int)1e9 + 7;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int N = (int)1e5 + 10;
const int SQN = 400;
const int LOGN = 30;

pt r[N];
int a[N];
bool used[N];

void solve() {
	int cases;
	scanf("%d\n", &cases);
	forn(cur_case, cases) {
		int m, k;
		scanf("\n%d %d\n", &m, &k);
		forn(i, k) {
			scanf("%d\n", &a[i]);
		}
		forn(i, m - 1) {
			scanf("%d %d\n", &r[i].X, &r[i].Y);
		}
		bool all_happy = true;
		int sum = 0;
		forn(i, m - 1) {
			if (all_happy && r[i].Y == 1) {
				all_happy = false;
				ms(used, false);
				forft(j, i, m - 1) {
					if (r[j].X != 0) {
						used[r[j].X - 1] = true;
					}
				}
				int min_val = INF;
				forn(j, k) {
					if (!used[j] && a[j] <= sum) {
						if (a[j] < min_val) {
							min_val = a[j];
						}
					}
				}
				forn(j, k) {
					if (!used[j] && a[j] <= sum) {
						a[j] -= min_val;
					}
				}
				sum -= min_val;
			}			
			if (r[i].X != 0) {
				a[r[i].X - 1]--;
			} else {
				sum++;
			}
		}
		forn(i, k) {
			if (a[i] <= sum) {
				printf("Y");
			} else {
				printf("N");
			}
		}
		printf("\n");
	}
}
 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cout << setprecision(10) << fixed;

	solve();

	return 0;
} 