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

string calc(string &s, int a, int b){
	string t = s.substr(0, a) + "$" + s, str;
	vector<int> z;
	z_f(t, z);
	bool no = 1;
	int n = t.size();
	for (int i = a + 1; i < n;){
		if (z[i] == a){
			i += a;
		}
		else if (no && n - i >= b){
			str = t.substr(i, b);
			i += b;
			no = 0;
		}
		else if (n - i >= b && t.substr(i, b) == str){
			i += b;
		}
		else {
			return "-";
		}
	}
	return str;
}

int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int len, i, k, n;
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
		int dop = min(len, n);
		for (i = 1; i <= dop; i++){
			for (k = 1; i + k <= n && k <= dop; k++){
				string ans_s = calc(s, i, k);
				if (ans_s != "-"){
					cout << "2\n" << s.substr(0, i) << endl;
					cout << ans_s;
					return 0;
				}
			}
		}
		cout << "3\na\nb\nc";		
	}
	
	return 0;
}