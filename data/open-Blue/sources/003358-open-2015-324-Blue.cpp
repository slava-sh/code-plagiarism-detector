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

int p[MAXN];

string s;
int l, n;

void prefix() {
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int tmp = i - 1;
		while (s[p[tmp]] != s[i] && tmp > 0) {
			tmp = p[tmp];
		}
		p[i] = p[tmp] + (s[p[tmp]] == s[i]);
		debug("p[%d] = %d\n", i, p[i]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> l;
	cin >> s;
	n = s.size();
	prefix();
	
	int tmp = n - p[n - 1];
	if (tmp <= l && n % tmp == 0) {
		cout << 1 << '\n';
		for (int i = 0; i < tmp; i++) {
			cout << s[i];
		}
		cout << '\n';
		return 0;
	}
	
	if (n <= l) {
		cout << 1 << '\n';
		cout << s << '\n';
	} else {
		cout << "2\na\nb\n";
	}
		
	return 0;
}
