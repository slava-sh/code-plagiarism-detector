#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>

#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
#define S second
#define F first


const int INF = int(1e9) + 7;
const ll INFll = int(1e18) + 7;
const ll md = 239;

using namespace std;


int k, ok[3], n, got, pref[20005], tm = 1, used[20005];
string s;

ll hsh[20005], pwr[20005];

ll geth(ll l, ll r){
	return hsh[r] - hsh[l - 1] * pwr[r - l + 1];
}


int main(){
//	ifstream cin ("test.in");
	cin >> k >> s;
	n = s.size();

	for (int i = 0; i < n; i++){
		ok[s[i] - 'a'] = 1;
	}
	for (int i = 0; i < 3; i++) got += ok[i];

	if (got == 1) {
		cout << 1 << '\n';
		for (int i = 0; i < 3 ; i++) 
			if (ok[i]) cout << char('a' + i) << '\n';
	} else if (got == 2){
		if (k >= n){
			cout << 1 << '\n' << s << '\n';
		} else {
			pref[0] = 0;
			for (int i = 1; i < n; i++){
				int d = pref[i - 1];
				while (d && s[i] != s[d]) d = pref[d - 1];
				if (s[i] == s[d]) pref[i] = d + 1;
				else pref[i] = d;
			}
			if (n % (n - pref[n - 1]) == 0 && (n - pref[n - 1]) <= k){
				cout << 1 << '\n';
				for (int i = 0; i < n - pref[n - 1]; i++) cout << s[i];
				cout << '\n';
			} else {
				cout << 2 << '\n';
				for (int i = 0; i < 3; i++){
					if (ok[i]) cout << char('a' + i) << '\n';
				}
			}
		}
	} else {
		if (k >= n){
			cout << 1 << '\n' << s << '\n';
		} else {
			pref[0] = 0;
			for (int i = 1; i < n; i++){
				int d = pref[i - 1];
				while (d && s[i] != s[d]) d = pref[d - 1];
				if (s[i] == s[d]) pref[i] = d + 1;
				else pref[i] = d;
			}
			if (n % (n - pref[n - 1]) == 0 && (n - pref[n - 1]) <= k){
				cout << 1 << '\n';
				for (int i = 0; i < n - pref[n - 1]; i++) cout << s[i];
				cout << '\n';
			} else {
				pwr[0] = 1;
				for (int i = 1; i < 20005; i++){
					pwr[i] = md * pwr[i - 1];
				}
				hsh[0] = 0;
				for (int i = 1; i <= n; i++){
					hsh[i] = hsh[i - 1] * md + s[i - 1];
				}
				for (int i = 0; i < k; i++){
					for (int j = i + 1; j < min(n, i + k + 1); j++){
						ll h1 = geth(1, i + 1), h2 = geth(i + 2, j + 1);
						tm++;
						queue <int> q;
						q.push(j + 1);
						used[j + 1] = tm;
						while (!q.empty()){
							int v = q.front();
							if (v == n){
								cout << 2 << '\n';
								for (int w = 0; w <= i; w++){
									cout << s[w];
								}
								cout << '\n';
								for (int w = i + 1; w <= j; w++){
									cout << s[w];
								}
								cout << '\n';
								return 0;
							}
							q.pop();
							if (v + i < n && (geth(v + 1, v + i + 1) == h1 || geth(v + 1, v + i + 1) == h2)){
								if (used[v + i + 1] != tm){
									q.push(v + i + 1);
									used[v + i + 1] = tm;
								}
							}
							if (v + (j - i - 1) < n &&(geth(v + 1, v + (j - i)) == h1 || geth(v + 1, v + (j - i)) == h2)){
								if (used[v + (j - i)] != tm){
									q.push(v + (j - i));
									used[v + (j - i)] = tm;
								}
							}
						}
					}
				}
				cout << 3 << '\n';
				cout << 'a' << '\n';
				cout << 'b' << '\n';
				cout << 'c' << '\n';
			}
		} 
	}
}