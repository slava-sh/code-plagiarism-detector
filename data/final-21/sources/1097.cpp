#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ull;

const ull prime = 31;
const int max_len = 100001;

vector< ull > lhash(max_len), rlhash(max_len), primes(max_len);

int n;

void calc_lhashes(const string &s) {
	lhash[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++)
		lhash[i] = lhash[i - 1] * prime + s[i] - 'a' + 1;

	rlhash[n - 1] = s[n - 1] - 'a' + 1;
	for (int i = n - 2; i >= 0; i--)
		rlhash[i] = rlhash[i + 1] * prime + s[i] - 'a' + 1;
}

bool is_palindrome(int l, int r) {
	ull left_lhash = lhash[r], right_lhash = rlhash[l];
	if (l != 0)
		left_lhash -= lhash[l - 1] * primes[r - l + 1];
	if (r != n - 1)
		right_lhash -= rlhash[r + 1] * primes[r - l + 1];
	return left_lhash == right_lhash;
}

#define NAME "inventory"
int main() {
	freopen(NAME ".in", "r", stdin);
	freopen(NAME ".out", "w", stdout);

	primes[0] = 1;
	for (int i = 1; i < max_len; i++)
		primes[i] = primes[i - 1] * prime;

	int k;
	cin >> k;
	cin.ignore();
	string s;
	for (int i = 0; i < k; i++) {
		cin >> s;
		n = s.length();
		calc_lhashes(s);
		
		if (is_palindrome(0, n - 1)) {
			cout << "0\n";
			continue;
		}

		bool f = false;
		for (int i = 0; i < n; i++) {
			if (is_palindrome(0, i) && is_palindrome(i + 1, n - 1)) {
				if (i % 2 == 1) {
					cout << ((i + 1) / 2) << "\n";
					f = true;
					break;
				}
				if ((n - i) % 2 == 1) {
					cout << (i + (n - i) / 2 + 1) << "\n";					
					f = true;
					break;
				}
			}
		}
		if (!f)
			cout << "-1\n";
	}

	return 0;
}