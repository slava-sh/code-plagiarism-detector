#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF (1E+9)
#define MAXN
#define MAXL
#define EPS (1E-9)
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PROBLEM "" 

vector <int> z_func(vector<int> s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, L = 0, R = 0; i < n; ++i) {
		if (i <= R)
			z[i] = min(R - i + 1, z[i - L]);
		while (i + z[i] < n && s[z[i]] == s[z[i] + i])
			++z[i];
		if (i + z[i] - 1 > R)
			L = i, R = i + z[i] - 1;
	}

	return z;
}

static int cnt = 300;

vector<int> getMin(vector<int> s) {
	for (int firstLen = 1; firstLen < s.size(); ++firstLen) {
		vector <int> tmp101;
		for (int i = 0; i < firstLen; ++i)
			tmp101.push_back(s[i]);
		tmp101.pb(cnt++);
		for (int i = 0; i < s.size(); ++i)
			tmp101.push_back(s[i]);
		vector<int> z = z_func(tmp101);

		vector<bool> tmp(s.size());

		for (int i = firstLen + 1; i < z.size(); ++i) {
			if (tmp[i - firstLen - 1] || z[i] < firstLen)
				continue;
			for (int j = i; j < i + z[i]; ++j)
				tmp[j - firstLen - 1] = 1;
		}

		int good = 1;
		for (int i = 0; i < s.size(); ++i)
			good = good && tmp[i];
		
		if (good) {
			tmp101.clear();
			for (int i = 0; i < firstLen; ++i)
				tmp101.push_back(s[i]);
			return tmp101;
		}
	}
	return s;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int L;
	string _s;
	vector <int> s;
	cin >> L >> _s;
	
	if (_s.length() <= L) {
		cout << 1 << endl << _s;
		return 0;
	}

	int n = _s.length();	

	s.resize(n);
	for (int i = 0; i < n; ++i)
		s[i] = _s[i];

	bool have[3] = {0, 0, 0};

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a')
			have[0] = 1;
		if (s[i] == 'b')
			have[1] = 1;
		if (s[i] == 'c')
			have[2] = 1;
	}

	int ans = have[0] + have[1] + have[2];

	if (ans == 1) {
		cout << ans << endl << _s[0];
		return 0;
	}

	for (int firstLen = 1; firstLen <= L; ++firstLen) {
		vector <int> tmp101;
		for (int i = 0; i < firstLen; ++i)
			tmp101.push_back(s[i]);
		tmp101.pb(cnt++);
		for (int i = 0; i < n; ++i)
			tmp101.push_back(s[i]);
		vector<int> z = z_func(tmp101);

		vector<bool> tmp(n);

		for (int i = firstLen + 1; i < z.size(); ++i) {
			if (tmp[i - firstLen - 1] || z[i] < firstLen)
				continue;
			for (int j = i; j < i + z[i]; ++j)
				tmp[j - firstLen - 1] = 1;
		}

		int good = 1;
		for (int i = 0; i < n; ++i)
			good = good && tmp[i];
		
		if (good) {
			cout << 1 << endl;
			for (int i = 0; i < firstLen; ++i)
				cout << (char)s[i];
			return 0;
		}
	}


	/////////////////////////////////////////////////////////////////2
	if (ans == 2) {
		cout << ans << endl;
		if (have[0])
			cout << 'a' << endl;
		if (have[1])
			cout << 'b' << endl;
		if (have[2])
			cout << 'c' << endl;
		return 0;
	}
	
	for (int firstLen = 1; firstLen <= L; ++firstLen) {
		vector <int> tmp101;
		for (int i = 0; i < firstLen; ++i)
			tmp101.push_back(s[i]);
		tmp101.pb(cnt++);
		for (int i = 0; i < n; ++i)
			tmp101.push_back(s[i]);
		vector<int> z = z_func(tmp101);
		vector<bool> tmp(n);

		for (int i = firstLen + 1; i < z.size(); ++i) {
			if (tmp[i - firstLen - 1] || z[i] < firstLen)
				continue;
			for (int j = i; j < i + z[i]; ++j)
				tmp[j - firstLen - 1] = 1;
		}

		vector<int> other;
		
		int i = 0;
		while (i < n && tmp[i])
			++i;
		for (i; i < n && !tmp[i]; ++i) {
			other.pb(s[i]);
		}
		
		other = getMin(other);

		tmp101 = other;
		tmp101.pb(cnt++);
		for (int i = 0; i < n; ++i)
			tmp101.pb(s[i]);
		z = z_func(tmp101);

		for (int i = other.size() + 1; i < z.size(); ++i) {
			if (tmp[i - other.size() - 1] || z[i] < other.size())
				continue;
			for (int j = i; j < i + z[i]; ++j)
				tmp[j - other.size() - 1] = 1;
		}

		int good = 1;

		for (int i = 0; i < n; ++i)
			good = good && tmp[i];

		if (good && other.size() <= L) {
			cout << 2 << endl;
			for (int i = 0; i < other.size(); ++i)
				cout << (char)other[i];
			cout << endl;
			for (int i = 0; i < firstLen; ++i)
				cout << (char)s[i];
			return 0;
		}

	}

	//worst case

	cout << "3\na\nb\nc\n";

	return 0;
}