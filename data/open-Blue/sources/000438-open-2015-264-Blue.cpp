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


using namespace std;


int k, ok[3], n, got;
string s;



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
			if (ok[i]) cout << char('a' + i);
	} else if (got == 2){
		if (k >= n){
			cout << 1 << '\n' << s << '\n';
		} else {
			cout << 2 << '\n';
			for (int i = 0; i < 3; i++){
				if (ok[i]) cout << char('a' + i) << '\n';
			}
		}
	} else {
		if (k >= n){
			cout << 1 << '\n' << s << '\n';
		} else {
			bool flag = true;
			if (n % 2 == 0 && k >= n / 2){
				for (int i = 0; i < n / 2; i++){
					if (s[i] != s[i + n / 2]) flag = false;
				}
			} else {
				flag = false;
			}
			if (!flag) {
				cout << 3 << '\n';
				cout << 'a' << '\n';
				cout << 'b' << '\n';
				cout << 'c' << '\n';
			} else {
				cout << 2 << '\n';
				for (int i = 0; i < n / 2; i++){
					cout << s[i];
				}
			}
		} 
	}
}