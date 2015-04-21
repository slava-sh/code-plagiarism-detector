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

#define ll long long

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

int p[MAXN];
int z[MAXN];
int dp[MAXN];

string s, tmp;
int l, n;

void zf() {
	z[0] = 0;
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		z[i] = min(z[i - tmp], z[tmp] + tmp - i - 1);
		z[i] = max(0, z[i]);
		while (z[i] + i < n && s[z[i] + i] == s[z[i]]) {
			z[i]++;
			tmp = i;
		}
	}
}

void prefix() {
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int tmp = i - 1;
		while (s[p[tmp]] != s[i] && tmp > 0) {
			tmp = p[tmp] - 1;
		}
		p[i] = p[tmp] + (s[p[tmp]] == s[i]);
	}
}

int zz[MAXN];
void zff(string s) {
	int n = s.size();
	zz[0] = 0;
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		zz[i] = min(zz[i - tmp], zz[tmp] + tmp - i - 1);
		zz[i] = max(0, z[i]);
		while (zz[i] + i < n && s[zz[i] + i] == s[zz[i]]) {
			zz[i]++;
			tmp = i;
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> l;
	cin >> s;
	n = s.size();
	prefix();
	zf();
	
	int tmp = n - p[n - 1];
	if (tmp <= l && n % tmp == 0) {
		cout << 1 << '\n';
		for (int i = 0; i < tmp; i++) {
			cout << s[i];
		}
		cout << '\n';
		return 0;
	}
	
	for (int i = 1; i <= l; i++) {
		int N = n;
		while (z[n - i] >= i) {
			n -= i;
		}
		for (int j = 1; j <= l; j++) {
			if (i + j > n) break;
			for (int e = 0; e < n; e++)
				dp[e] = 0;
			dp[i - 1] = 1;
			
			string tmp = s;
			for (int q = n - j; q < n; q++) {
				tmp = s[q] + tmp;
			}
			zff(tmp);
			
			for (int pos = i; pos + j < n; pos++) {
				bool can;
				int tmp = pos - i;
				if (dp[tmp] && z[pos - i] >= i)
					dp[pos] = 1;
				
				if (pos + 1 >= j) {
					can = true;
					for (tmp = pos; tmp > pos - j; tmp--) {
						if (s[tmp] != s[n - 1 - pos + tmp]) {
							can = false;
						}
					}
					if (dp[tmp] && can)
						dp[pos] = 1;
				}
			}
			if (dp[n - j - 1]) {
				cout << 2 << '\n';
				for (int k = 0; k < i; k++)
					cout << s[k];
				cout << '\n';
				for (int k = n - j; k < n; k++)
					cout << s[k];
				return 0;
			}
		}
		n = N;
	}
	
	if (n <= l) {
		cout << 1 << '\n';
		cout << s << '\n';
	} else {
		cout << "3\na\nb\nc\n";
	}
		
	return 0;
}
