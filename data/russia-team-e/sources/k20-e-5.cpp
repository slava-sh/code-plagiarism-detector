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
		string t[4], f[4][6];
		int g = - 1, o = - 1;
		for(int j = 1; j <= 11; ++j) {
			cin >> s[j];
		}
		for(int j = 1; j <= 3; ++j)
			for(int e = 1; e <= j; ++e)
				t[j] += s[e];   
		bool ok = true;
		for(int j = 1; j <= 3; ++j) {
			if(pos[t[j]])
				for(int u = 1; u <= 5; ++u)
					for(int e = j + 1; e <= j + u; ++e)
						f[j][u] += s[e];     
		}
		string F = "", S = "";
		for(int e = 1; e <= 3; ++e) {
			if(!ok) break;
			for(int u = 1; u <= 3; ++u)	{
				if(!ok) break;
				for(int j = 1; j <= 5; ++j) {
					if(poso[f[u][j]] == pos[t[e]] && poso[f[u][j]]) {
						F = f[u][j], S = t[e];
						ok = false;
						break;
					}
				}
			}
		}   
		o = int(F.length() + S.length());
		if(ok || s[o + 1] == '0' || o == -1) {
			cout << "Incorrect" << endl;
			continue;
		}                                
		int r = 11 - o;
		cout << "+" << S << "(" << F << ")";
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