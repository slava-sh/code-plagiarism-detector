#include <iostream>
#include <algorithm> 
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <vector>
#include <stdio.h>

using namespace std;

int p = 151031, mod = 1000 * 1000 * 1000 + 7, h[20010], pw[20010], N;

bool check(int len) {
	int hash = (((h[len] - h[0]) % mod) + mod) % mod;
	for(int i = len + 1; i <= N; i += len) {
		int hashNew = (((h[i + len - 1] - h[i - 1]) % mod) + mod) % mod;
		if((1LL * hash * pw[i - 1]) % mod != hashNew)
			return 0;
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int L;
	cin >> L;
	string s;
	cin >> s;
	bool a = 0, b = 0, c = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] == 'a')
			a = 1;
		if(s[i] == 'b')
			b = 1;
		if(s[i] == 'c')
			c = 1;
	}
	N = (int)s.length();
	pw[0] = 1;
	for(int i = 1; i <= N; i++)
		pw[i] = (1LL * pw[i - 1] * p) % mod;
	for(int i = 0; i < N; i++) {
		h[i + 1] = (h[i] + 1LL * pw[i] * s[i]) % mod;
	}
	if(a + b + c == 1) {
		cout << a + b + c << endl;
		if(a)
			cout << "a" << endl;
		if(b)
			cout << "b" << endl;
		if(c) 
			cout << "c" << endl;
	}
	else if(a + b + c == 2) {
		int len = 1;
		while(len * len <= N) {
			if(N % len == 0) {
				if(check(len) && len <= L) {
					cout << 1 << endl;
					for(int i = 0; i < len; i++)
						cout << s[i];
					cout << endl;
					return 0;
				}
				if(check(N / len) && N / len <= L) {
					cout << 1 << endl;
					for(int i = 0; i < N / len; i++)
						cout << s[i];
					cout << endl;
					return 0;
				}
			}
			len++;
		}
		cout << 2 << endl;
		if(a)
			cout << "a" << endl;
		if(b)
			cout << "b" << endl;
		if(c) 
			cout << "c" << endl;
	}
	else {
		map<pair<int, int>, int> list;
		for(int i = 0; i < N; i++) {
			for(int j = i; j < N; j++) {
				if(j - i + 1 > L)
					break;
				int hash = (((h[j + 1] - h[i]) % mod) + mod) % mod;
				list[{(1LL * hash * pw[N - i]) % mod, j - i + 1}] += j - i + 1;
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = i; j < N; j++) {
				for(int l = j + 1; l < N; l++) {
					for(int r = l; r < N; r++) {
						int hash = (((h[j + 1] - h[i]) % mod) + mod) % mod;
						int hash1 = (((h[r + 1] - h[l]) % mod) + mod) % mod;
						if(list[{(1LL * hash * pw[N - i]) % mod, j - i + 1}] + list[{(1LL * hash1 * pw[N - l]) % mod, r - l + 1}] == N) {
							cout << 2 << endl;
							string res = "";
							for(int k = i; k <= j; k++)
								res += s[k];
							cout << res << endl;
							res = "";
							for(int k = l; k <= r; k++)
								res += s[k];
							cout << res << endl;
							return 0;
						}
					}
				}
			}
		}
		cout << 3 << endl;
		cout << 'a' << endl;
		cout << 'b' << endl;
		cout << 'c' << endl;
	}
	return 0;
}