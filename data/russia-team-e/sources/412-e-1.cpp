#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#include<queue>
#include<string>
#include<map>

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define next next_asjkdh
using namespace  std;


string c, d;
int k;

map<string, string> Map;
string tmp;
string get(const string &s, int x) {
	tmp = "";
	for (int i = 0; i <= x; ++i)
		tmp += s[i];
	return tmp;
}

string gete(const string &s, int x) {
	tmp = "";
	for (int i = x + 1; i < s.size(); ++i)
		tmp += s[i];
	return tmp;
}

void parse(string s) {
	if (s.length() == 3) {
		cout << s;
	} else
	if (s.length() == 4)
		cout << s[0] << s[1] << "-" << s[2] << s[3];
	else if (s.length() == 5)
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4];
	else if (s.length() == 6)
		cout << s[0] << s[1] << "-" << s[2] << s[3] << '-' << s[4] << s[5];
	else if (s.length() == 7)
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4] << '-' << s[5] << s[6];
}

void solve(string s) {
	for (int i = 0; i < s.length(); ++i) {
		d = get(s, i);
		if (Map.count(d) > 0) {
			if (s[i + 1] == '0') continue;
			cout << Map[d];
			parse(gete(s, i));
			cout << "\n";
			return;
		}
	}
	cout << "Incorrect\n";
}

int main(void) {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c >> k;
		for (int i = 0; i < k; ++i) {
			cin >> d;
			Map[c + d] =  "+" + c + "(" + d + ")";
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> c;
		solve(c);
	}
	return 0;
}