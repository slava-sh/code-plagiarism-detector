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

#define ll long long

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

class point {
public:
	ll x, y;
	int i;
	point(ll x = 0, ll y = 0, int i = 0) : x(x), y(y), i(i) {};
	
	const point operator-(const point b) const {
		return point(x - b.x, y - b.y);
	}
	
	const point operator+(const point b) const {
		return point(x + b.x, y + b.y);
	}
	
	const ll operator%(const point b) const {
		return x * b.y - y * b.x;
	}
	
	const ll operator*(const point b) const {
		return x * b.x + y * b.y;
	}
	
	const bool operator<(const point b) const {
		return x < b.x;
	}
};

vector<point> a[MAXN];
vector< pair<point, int> > points;
int pos[MAXN];
ll A, B;
int n;

set<int> g[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
		
	cin >> A >> B;
	cin >> n;
	debug("A = %d, B = %d\nn = %d\n", (int)A, (int)B, n);
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		for (int j = 0; j < l + 1; j++) {
			ll x, y;
			cin >> x >> y;
			a[i].push_back(point(x, y, i));
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][0].y < a[j][0].y)
				g[i].insert(j);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (point j : a[i]) {
			//debug("point (%I64d, %I64d) from line %d under construction\n", j.x, j.y, j.i);
			points.push_back(make_pair(point(j.x, j.y, j.i), i));
		}
	}
	debug("\n");
	sort(points.begin(), points.end());
	
	debug("\nLet's Rock!\n\n");
	
	for (auto p : points) {
		if (p.first.x == A) continue;
		
		debug("point (%I64d, %I64d) from line %d under investigation\n", p.first.x, p.first.y, p.first.i);
		
		for (int i = 0; i < n; i++) { //TODO
			while (a[i][pos[i] + 1] < p.first)
				pos[i]++;
		}
		

		for (int i = 0; i < n; i++) {
			int up_pos = i;
			point up1 = a[up_pos][pos[up_pos]];
			point up2 = a[up_pos][pos[up_pos] + 1];
			debug("Up vector = (%I64d, %I64d) --> (%I64d, %I64d) ||| up %% p = %I64d \n", up1.x, up1.y, up2.x, up2.y, (up2 - up1) % (p.first - up1));
			bool up = (up2 - up1) % (p.first - up1) < 0;
			if (up) {
				g[p.first.i].insert(i);
			}
		}
		debug("______________________________________\n");
	}
	
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			if (g[j].count(i)) {
				printf("No\n%d %d\n", i + 1, j + 1);
				return 0;
			}
		}
	}
	
	cout << "Yes\n";
		
	return 0;
}
