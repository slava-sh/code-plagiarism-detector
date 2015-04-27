#include <bits/stdc++.h>

using namespace std;

const int P = 41, MOD = 1e9 + 7;

int n, L;
string s, cycle;
/*vector<int> hash;

int powmod(int a, int p) {
	if (p == 0) {
		return 1;
	}

	int prev = powmod(a, p >> 1);
	if (p & 1) {
		return ((1ll * prev * prev) % MOD) * a % MOD;
	}
	else {
		return (1ll * prev * prev) % MOD;
	}
}

int get_hash(int L, int R) {
	return hash[R] - hash[L] * powmod(P, R - L);
}
*/
bool eq(int L1, int R1, int L2, int R2) {
	if (R1 - L1 != R2 - L2)
		return false;
	else {
		/*
		return get_hash(L1, R1) == get_hash(L2, R2);
		*/
		for (int i = 0; i < R1 - L1; i++) {
			if (s[L1 + i] != s[L2 + i]) {
				return false;
			}
		}
		return true;
	}

}

bool check_cycle() {
	if (n % (cycle.size() != 0)) {
		return false;
	}
	int len = cycle.size();
	int parts = n / len;
	for (int i = 1; i < parts; i++) {
		if (!(eq(len * (i - 1), len * i, len * i, len * (i + 1)))) {
			//cerr << i << " -> fail";
			return false;
		}
	}
	return true;
}

bool check_cyclic() {
	cycle = "";
	for (int i = 0; i < L; i++) {
		cycle = cycle + s[i];
		//cerr << cycle << " ";
		if (check_cycle()) {
			return true;
		}
		//cerr << "\n";
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> L >> s;
	n = s.size();
	
	if (n <= L) {
		cout << 1;
		return 0;
	}

	//hash.resize(n + 1, 0);
	bool has_a = false, has_b = false, has_c = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a')
			has_a = true;
		if (s[i] == 'b')
			has_b = true;
		if (s[i] == 'c')
			has_c = true;
		//hash[i + 1] = (hash[i] * P + (s[i] - 'a')) % MOD;
	}

	if (has_a + has_b + has_c == 1) {
		cout << "1\n";
		if (has_a)
			cout << 'a';
		if (has_b)
			cout << 'b';
		if (has_c)
			cout << 'c';
	}
	else if (has_a + has_b + has_c == 2) {
		if (check_cyclic()) {
			cout << "1\n" << cycle;
		}
		else {
			cout << "2\n";
			if (has_a)
				cout << "a\n";
			if (has_b)
				cout << "b\n";
			if (has_c)
				cout << "c\n";
		}
	}
	return 0;
}