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
const ull md = 97;
const ull m2 = 239;

using namespace std;


int k, ok[3], n, got, pref[20005], t = 1, used[20005];
string s;

ull hsh[20005], pwr[20005];
ll h2[20005], p2[20005];

ull geth(ll l, ll r){
	return hsh[r] - hsh[l - 1] * pwr[r - l + 1];
}
ll g2(ll l, ll r){
	return (2 * INF + h2[r] - (h2[l - 1] * p2[r - l + 1]) % INF) % INF;
}

int main(){
	srand(time(NULL));
//	ifstream cin ("test.in");
	cin >> k >> s;
	n = s.size();

	for (int i = 0; i < k; i++){
		if (n % (i + 1) == 0){
			string s1 = "";
			bool flag = true;
			for (int j = 0; j <= i; j++) s1 += s[j];
			for (int j = 1; j < n / (i + 1); j++){
				for (int q = j * (i + 1); q < (j + 1) * (i + 1); q++){
					if (s1[q - j * (i + 1)] != s[q]){
						flag = false;
						break;
					}
				}
			}
			if (flag){
				cout << 1 << '\n';
				for (int j = 0; j <= i; j++){
					cout << s[j];
				}
				return 0;
			}
		}
	}
	for (int i = 0; i < k; i++){
		for (int j = i + 1; j < min(i + 1 + k, n); j++){
			string s1 = "", s2 = "";
			for (int q = 0; q <= i; q++) s1 += s[q];
			for (int q = i + 1; q <= j; q++) s2 += s[q];
			int m1 = s1.size(), m2 = s2.size();
			vector <int> dp;
			dp.assign(n + 1, 0);
			dp[j + 1] = 1;
			for (int q = j + 1; q < n; q++){
				if (dp[q]){
					if (q + m1 - 1 < n){
						bool flag = true;
						for (int w = q; w < q + m1; w++){
							if (s[w] != s1[w - q]) {
								flag = false;
								break;
							}
						}
						if (flag){
							dp[q + m1] = 1;
						}
					}
					if (q + m2 - 1 < n){
						bool flag = true;
						for (int w = q; w < q + m2; w++){
							if (s[w] != s2[w - q]) {
								flag = false;
								break;
							}
						}
						if (flag){
							dp[q + m2] = 1;
						}
					}

				}
			}
			if (dp[n] == 1){
				cout << 2 << '\n';
				cout << s1 << '\n' << s2 << '\n';
				return 0;
			}
		}
	}
	cout << 3 << '\n' << 'a' << '\n' << 'b' << '\n' << 'c' << '\n';
	return 0;


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
				if (k >= (n + 1) / 2){
					cout << 2 << '\n';
					for (int i = 0; i < k; i++){
						cout << s[i];
					}
					cout << '\n';
					for (int i = k; i < n; i++){
						cout << s[i];
					}
					cout << '\n';
				}
				pwr[0] = 1;
				for (int i = 1; i < 20005; i++){
					pwr[i] = md * pwr[i - 1];
				}
				hsh[0] = 0;
				for (int i = 1; i <= n; i++){
					hsh[i] = hsh[i - 1] * md + s[i - 1];
				}

				p2[0] = 1;
				for (int i = 1; i < 20005; i++){
					p2[i] = (m2 * p2[i - 1]) % INF;
				}
				h2[0] = 0;
				for (int i = 1; i <= n; i++){
					h2[i] = (h2[i - 1] * m2 + s[i - 1]) % INF;
				}

				for (int i = 0; i < k; i++){
					for (int j = i + 1; j < min(n, i + k + 1); j++){
						ull h1 = geth(1, i + 1), h2 = geth(i + 2, j + 1);
						ll hh1 = g2(1, i + 1), hh2 = g2(i + 2, j + 1);
						t++;
						queue <int> q;
						q.push(j + 1);
						used[j + 1] = t;
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
							if (v + i < n && (geth(v + 1, v + i + 1) == h1) && g2(v + 1, v + i + 1) == hh1){
								if (used[v + i + 1] != t){
									q.push(v + i + 1);
									used[v + i + 1] = t;
								}
							}
							if (v + (j - i - 1) < n &&(geth(v + 1, v + (j - i)) == h2) && g2(v + 1, v + (j - i)) == hh2){
								if (used[v + (j - i)] != t){
									q.push(v + (j - i));
									used[v + (j - i)] = t;
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