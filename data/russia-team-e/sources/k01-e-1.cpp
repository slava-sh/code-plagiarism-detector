#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define INF 2e9
#define mod 1000000007
#define fi first
#define se second
#define fname "numbers"
#define re return

typedef long long ll;

ll n, c, k, x, m, cou, reg;
map <ll, ll > q[1111], qq;
string s;

int main() {
	
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> c >> k;
		qq[c] = 1;
		for(int j = 1; j <= k; j++) {
			cin >> x;
			q[c][x] = 1;
		}

	}

	cin >> m;

	for(int i = 1; i <= m; i++) {
		cin >> s;
		bool  ok = 1, go = 0, kk = 1;
		
		if(s[0] == '0') ok = 0;
		for(int h = 1; h <= 3; h++) {
		    cou = 0;
			for(int o = 0; o < h; o++) cou = cou * 10 + (s[o] - 48);

			for(int g = 3; g <= 5; g++) {
				kk = 1;
				reg = 0;
				if(s[h + g] == '0') kk = 0;
				if(s[h] == '0') kk = 0;
				for(int o = h; o < h + g; o++) reg = reg * 10 + (s[o] - 48);
				if(ok && kk && qq.count(cou) && q[cou].count(reg)) {
					cout << "+" << cou << "(" << reg << ")";
					if(11 - h - g == 3) cout << s.substr(h + g, 3);
					else
					if(11 - h - g == 4) cout << s.substr(h + g, 2) << "-" << s.substr(h + g + 2, 2);
					else
					if(11 - h - g == 5) cout << s.substr(h + g, 3) << "-" << s.substr(h + g + 3, 2);
					else
					if(11 - h - g == 6) cout << s.substr(h + g, 2) << "-" << s.substr(h + g + 2, 2) << "-" << s.substr(h + g + 4, 2);
					else
					cout << s.substr(h + g, 3) << "-" << s.substr(h + g + 3, 2) << "-" << s.substr(h + g + 5, 2);
					go = 1;
				}

				}
							
		}
		if(!go) cout<< "Incorrect";
		cout <<endl;
		
	}
	re 0;
}