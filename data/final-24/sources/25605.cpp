#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

#ifdef _DEBUG
#define stop system("pause");
#else
#define stop ;
#endif

using namespace std;

int p[1000];
string s, s1, sf;

void prefix() {
	p[0] = 0;
	int k;
	for (int i = 1; i < sf.size(); i++) {
		k = p[i - 1];
		while (k > 0 && s[k] != s[i]) {
			k = p[k - 1];
		}
		if (s[k] == s[i]) {
			k++;
		}
		p[i] = k;
	}
	for (int i = 0; i < s.size(); i++) {
		cout << p[i];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	cin >> s;
	if (s.size() < k) {
		k = s.size();
	}
	for (int i = 0; i < s.size() - k + 1; i++) {
		s1 = "";
		for (int j = 0; j < k; j++) {
			s1 += s[i + j];
			sf = s1 + "$" + s;
			p[0] = 0;
			int k;
			for (int i = 1; i < sf.size(); i++) {
				k = p[i - 1];
				while (k > 0 && sf[k] != sf[i]) {
					k = p[k - 1];
				}
				if (sf[k] == sf[i]) {
					k++;
				}
				p[i] = k;
			}
			int st = sf.size() - 1;
			while (p[st] == s1.size()) {
				st -= s1.size();
			}
			if (sf[st] == '$') {
				cout << "1\n";
				cout << s1;
				stop;
				return 0;
			}
		}
	}
	cout << "2\n";
	cout << "a\nb";


	stop;
	return 0;
}