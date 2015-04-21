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

const int MAXN = 22000;

string s, s2;
int L;
int z[MAXN];

int main() {
	cin >> L;
	cin >> s;
	s2 = s + s;
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
	}
	if (!flb) {
		cout << 2 << "\n";
		cout << "a\nc\n";
	}
	if (!flc) {
		cout << 2 << "\n";
		cout << "b\na\n";
	}

	return 0;
}

