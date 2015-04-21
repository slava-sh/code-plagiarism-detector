#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 42000;

string s, s2;
int L;
int z[MAXN];
int zz[MAXN];
int bd[MAXN];

int n;





void check() {
	for (int i = 1; i <= L; ++i) {
//		if (bd[i])
//			continue;
		int now = i;
		while (now + i <= n && z[now] >= i)
			now += i, bd[now] = 1;

		zz[now] = 0;
		int l = now;
		int r = now;
		for (int j = now + 1; j < n; ++j) {
			if (r > j)
				zz[j] = min(r - j, zz[j - l + now]);
			while (j + zz[j] < n && s[j + zz[j]] == s[now + zz[j]])
				++zz[j];
			if (zz[j] > r)
				r = zz[j], l = j;
		}

		for (int j = now + 1; j <= now + L && j <= n; ++j) {
			int l = j - now;
			int nn = j;
			int fl = 0;
			while (nn < n) {
				if (z[nn] >= i)
					nn += i;
				else if (zz[nn] >= l)
					nn += l;
				else {
					fl = 1;
					break;
				}
			}
			if (!fl) {
				cout << "2\n";
				for (int ii = 0; ii < i; ++ii)
					cout << s[ii];
				cout << "\n";
				for (int ii = now; ii < j; ++ii)
					cout << s[ii];
				exit(0);
			}
		}

	}
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> L;
	cin >> s;
	s2 = s + s;
	n = s.size();
	z[0] = 0;
	int l = 0;
	int r = 0;
	for (int i = 1; i < (int)s2.size(); ++i) {
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while (i + z[i] < (int)s2.size() && s2[i + z[i]] == s2[z[i]])
			++z[i];
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}

	for (int i = 1; i <= min((int)s.size(), L); ++i)
		if (z[i] >= (int)s.size()) {
			cout << 1 << "\n";
			for (int j = 0; j < i; ++j)
				cout << s[j];
			return 0;
		}

	int fla = 0;
	int flb = 0;
	int flc = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'a')
			fla = 1;
		if (s[i] == 'b')
			flb = 1;
		if (s[i] == 'c')
			flc = 1;
	}

	if (!fla) {
		cout << 2 << "\n";
		cout << "b\nc\n";
		return 0;
	}
	if (!flb) {
		cout << 2 << "\n";
		cout << "a\nc\n";
		return 0;
	}
	if (!flc) {
		cout << 2 << "\n";
		cout << "b\na\n";
		return 0;
	}

	if (2 * L >= n) {
		cout << "2\n";
		for (int i = 0; i < L; ++i)
			cout << s[i];
		cout << "\n";
		for (int i = L; i < (int)s.size(); ++i)
			cout << s[i];
		return 0;
	}

	check();

	cout << "3\na\nb\nc\n";

	return 0;
}

