#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

set<string> s;
set<pair<string, string> > s1;
long long n, m, kol = 0, c1;
string a, b, d, c, k;
bool t = false;

string ans(string x) {
	string s = "";
	if (x.length() == 3)
	{
		s += x[0];
		s += x[1];
		s += x[2];
	}
	else if (x.length() == 4) {
		s = x[0];
		s+= x[1];
		s+= '-';
		s+= x[2];
		s+= x[3];
	}
	else if (x.length() == 5) {
		s = x[0];
		s+= x[1];
		s+= x[2];
		s+= '-';
		s+= x[3];
		s+= x[4];
	}
	else if (x.length() == 6) {
		s = x[0];
		s+= x[1];
		s+= '-';
		s+= x[2];
		s+= x[3];
		s+= '-';
		s+= x[4];
		s+= x[5];
	}
	else
	{
		s = x[0];
		s+= x[1];
		s+= x[2];
		s+= '-';
		s+= x[3];
		s+= x[4];
		s+= '-';
		s+= x[5];
		s+= x[6];
	}
	return s;
}

int main()
{
	FILE *in, *out;
	in = freopen("numbers.in", "r", stdin);
	out = freopen("numbers.out", "w", stdout);
//-------------------------------------------------------------------

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k >> c1;
		if (k[0] != '0') {
		s.insert(k);
		for (int j = 0; j < c1; j++) {
			cin >> a;
			if (a[0] != '0') s1.insert(make_pair(k, a));
		}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		b = "";
		c = "";
		d = "";
		//1
		b = a[0];
		if (s.find(b) != s.end()) {
			c = "";
			for (int j = 1; j <= 3; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 4; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 1; j <= 4; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 5; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 1; j <= 5; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 6; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
		}

		//2
		b = a[0];
		b+= a[1];
		if (s.find(b) != s.end()) {
			c = "";
			for (int j = 2; j <= 4; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 5; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 2; j <= 5; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 6; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 2; j <= 6; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 7; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
		}

		//3
		b = a[0];
		b+= a[1];
		b+= a[2];
		if (s.find(b) != s.end()) {
			c = "";
			for (int j = 3; j <= 5; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 6; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 3; j <= 6; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 7; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
			c = "";
			for (int j = 3; j <= 7; j++)
				c += a[j];
			if (s1.find(make_pair(b, c)) != s1.end()) {
				d = "";
				for (int j = 8; j < 11; j++)
					d += a[j];
				if (d[0] == '0')
				{
					cout << "Incorrect" << endl;
					continue;
				}
				cout << '+' << b << '(' << c << ')' << ans(d) << endl;
				continue;
			}
		}
		cout << "Incorrect" << endl;
	}
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
