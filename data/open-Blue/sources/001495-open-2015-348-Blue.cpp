#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define localn
#define task "paul"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



void z_f(string &s, vector<int> &z){
	int n = s.size(), l, r, i;
	z.clear();
	z.resize(n);
	for (i = 1, r = l = 0; i < n; i++){
		if (i < r){
			z[i] = min(z[i - l], r - i);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
			z[i]++;
		}
		if (i + z[i] > r){
			l = i;
			r = i + z[i];
		}
	}
}

ll gcd(ll a, ll b){
	return (b ? gcd(b, a % b) : a);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int len, i, n;
	string s;

	cin >> len >> s;
	n = s.size();

	if (len >= n){
		cout << "1\n" << s;
		return 0;
	}

	vector<int> z;
	z_f(s, z);

	for (i = 0; i < n; i++){
		if (i + z[i] == n && n % i == 0 && i <= len){
			cout << 1 << endl;
			cout << s.substr(0, i);
			return 0;
		}
	}

	char mark[5];
	fill(mark, mark + 5, 0);
	for (i = 0; i < n; i++){
		mark[s[i] - 'a'] = 1;
	}
	int cnt = 0;
	for (i = 0; i < 3; i++){
		if (mark[i]){
			cnt++;
		}
	}
	if (cnt == 2){
		cout << "2\n";
		for (i = 0; i < 3; i++){
			if (mark[i]){
				cout << (char)(i + 'a') << endl;
			}
		}
	}
	else {
		vector<int> z1, z2;

		for (i = 1; i <= min(len, n); i++){
			string t = s.substr(0, i) + "$" + s;
			z_f(t, z1);

			bool ok = 0;
			int j = -1, k = -1, l = -1;
			ll obs = 1;
			for (k = i + i + 1; k < i + n + 1; k++){
				if (obs > len){
					break;
				}
				if (z1[k] != i){
					for (j = k + 1; j < i + n + 1 && z1[j] != i; j++);
					if (l == -1){
						l = k;
					}
					string str = t.substr(k, j - k);
					z_f(str, z2);
					for (j = 0; j < str.size(); j++){
						if (j + z2[j] == str.size() && str.size() % j == 0){
							obs = lcm(obs, j);
							break;
						}
					}
					k += str.size() - 1;
				}
				else {
					k += i - 1;
				}
			}
			
			if (obs > len){
				continue;
			}
			for (j = i + 1; j < i + n + 1; j++){
				if (z1[j] == i){
					j += i - 1;
				}
				else {
					int v;
					for (v = l; j < i + n + 1 && v < l + obs; j++, v++){
						if (t[j] != t[v]){
							break;
						}
					}
					if (v < l + obs){
						ok = 1;
					}
					if (ok){
						break;
					}
					j--;
				}
			}
			if (!ok){
				cout << "2\n";
				cout << t.substr(0, i) << endl;
				cout << t.substr(l, obs);
				return 0;
			}
		}
		cout << "3\na\nb\nc";
	}
	
	return 0;
}