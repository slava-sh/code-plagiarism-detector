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


int n, a[100005], cnt = 0, q;


int main(){
//	ifstream cin ("test.in");
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cnt = 0;
	for (int i = 1; i < n; i++){
		if (a[i] != a[i - 1]) cnt++;
	}
	cnt++;
	cin >> q;
	if (n == 1){
		for (int i = 0; i < q; i++){
			cout << 1 << '\n';
		}
		return 0;
	}
	for (int i = 0; i < q; i++){
		int p, c;
		cin >> p >> c;
		p--;
		if (a[p] != c){
			if (!p){
				if (a[p] == a[p + 1]) cnt++;
				else if (c == a[p + 1]) cnt--;
				a[p] = c;
			} else if (p == n - 1){
				if (a[p] == a[p - 1]) cnt++;
				else if (c == a[p - 1]) cnt--;
				a[p] = c;
			} else {
				if (a[p] != a[p - 1] && c == a[p - 1]) cnt--;
				if (a[p] == a[p - 1] && c != a[p - 1]) cnt++;
				if (a[p] != a[p + 1] && c == a[p + 1]) cnt--;
				if (a[p] == a[p + 1] && c != a[p + 1]) cnt++;
				a[p] = c;
			}
		}
		cout << cnt << '\n';
	}
}