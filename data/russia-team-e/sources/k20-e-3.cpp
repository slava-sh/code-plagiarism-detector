#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define fname "numbers"
#define pb push_back
#define mp make_pair
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

int n, m, k;
map <string, int> poso; 
map <string, int> pos;

string c[101], v[101];

int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i] >> k;
		pos[c[i]] = i;
		for(int j = 1; j <= k; ++j) {
			cin >> v[j];
			poso[v[j]] = i;
		}
	}
	cin >> m;
	char s[15];
	for(int i = 1; i <= m; ++i) {
		string t = "", f = "";
		int g = - 1, o = - 1;
		for(int j = 1; j <= 11; ++j) {
			cin >> s[j];
		}
		for(int j = 1; j <= 3; ++j) {
			t += s[j];
			if(pos[t]) {
				g = j;
				break;
			}
		}
		if(g == -1) {
			cout << "Incorrect" << endl;
			continue;
		}
		for(int j = g + 1; j <= g + 6; ++j) {
			f += s[j];
			if(poso[f]) {
				o = j;
				break;
			}
		}
		if(o == -1 || (poso[f] != pos[t]) || s[o + 1] == '0') {
			cout << "Incorrect" << endl;
			continue;
		}

		int r = 11 - o;
		cout << "+" << t << "(" << f << ")";
		for(int j = o + 1; j <= 11; ++j) {
			if(r == 4) {
				if(j == 10) 
					cout << "-";
			}
			if(r == 5) {
				if(j == 10)
					cout << "-";
			}
			if(r == 6) {
				if(j == 8 || j == 10)
					cout << "-";
			}
			if(r == 7) {
				if(j == 8 || j == 10) 
					cout << "-";
			}
			cout << s[j];
		}
		cout << endl;
	}
			
	return 0;
}