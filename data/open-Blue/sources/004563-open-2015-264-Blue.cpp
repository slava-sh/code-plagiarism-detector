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

using namespace std;


int k, ok[3], n, got, pref[20005], t = 1, used[20005];
string s;

ull hsh[20005], pwr[20005];

ull geth(ll l, ll r){
	return hsh[r] - hsh[l - 1] * pwr[r - l + 1];
}

int main(){
	srand(time(NULL));
//	ifstream cin ("test.in");
	cin >> k >> s;
/*	int fff = clock();
	k = 499;
	s.resize(1000);
	for (int i = 0; i < 1000; i++){
		s[i] = char('a' + rand()%3);
	}*/
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
				for (int i = 0; i < k; i++){
					vector <int> strt;
					ull h1 = geth(1, i + 1);
					strt.pb(i + 1);
					for (int j = (i + 1) * 2; j < n; j += i + 1){
						if (geth(j - i, j) == h1) strt.pb(j);
						else break;
					}
					for (int e = strt.size() - 1; e < strt.size(); e++){
						for (int j = strt[e]; j < min(n, strt[e] + k); j++){
							ull h2 = geth(strt[e] + 1, j + 1);
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
									for (int w = strt[e]; w <= j; w++){
										cout << s[w];
									}
									cout << '\n';
						//			cout << clock() - fff;
									return 0;
								}
								q.pop();
								if (v + i < n && (geth(v + 1, v + i + 1) == h1)){
									if (used[v + i + 1] != t){
										q.push(v + i + 1);
										used[v + i + 1] = t;
									}
								}
								if (v + (j - strt[e]) < n &&(geth(v + 1, v + (j - strt[e] + 1)) == h2)){
									if (used[v + (j - strt[e] + 1)] != t){
										q.push(v + (j - strt[e] + 1));
										used[v + (j - strt[e] + 1)] = t;
									}
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
//	cout << clock() - fff;
}