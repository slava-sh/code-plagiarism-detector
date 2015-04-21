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


using namespace std;


ll INFll;


int n, m, nn = 1, a[1000005], ra[1000005], ok[1000005], ans = 0, al, ar, k = 0;
vector <int> u, d, nu, nd, tree, psh;

void push (int v){
	tree[2 * v] += psh[v];
	tree[2 * v + 1] += psh[v];
	psh[2 * v] += psh[v];
	psh[2 * v + 1] += psh[v];
	psh[v] = 0;
}

void add(int v, int l, int r, int a, int b, int x){
	if (r < a || l > b) return;
	if (l >= a && r <= b) {
		tree[v] += x;
		psh[v] += x;
		return;
	}
	push(v);
	add(2 * v, l, (l + r) / 2, a, b, x);
	add(2 * v + 1, (l + r) / 2 + 1, r, a, b, x);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}


void getmax(int v){
	if (v < m){
		push(v);
		if (tree[2 * v] > tree[2 * v + 1]){
			getmax(2 * v);
		} else {
			getmax(2 * v + 1);
		}
	} else {
		if (tree[v] > ans){
			ans = tree[v];
			ar = k;
			al = nu[v - m];
		}
	}
}


int main(){
	INFll = 1e18;
	INFll *= 2;
	srand(time(NULL));
//	ifstream cin ("test.in");
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		ra[a[i]] = i;
	}
	u.pb(a[0]);
	nu.pb(0);
	for (int i = 1; i < n; i++){
		if (a[i] > u.back()){
			u.pb(a[i]);
			nu.pb(i);
		}
	}
	if (u.size() == n){
		cout << -1 << " " << -1 << '\n';
		return 0;
	}
	d.pb(a[n - 1]);
	nd.pb(n - 1);
	for (int i = n - 2; i >=0; i--){
		if (a[i] < d.back()){
			d.pb(a[i]);
			nd.pb(i);
		}
	}
	m = 1;
	nn = u.size();
	while (nn){
		m <<=1;
		nn >>=1;
	}
	nn = u.size();
	tree.resize(2 * m, 0);
	psh.resize(2 * m, 0);
	k = n - 1;
	for (int i = n - 1; i >= d[0]; i--){
		ok[i] = 1;
		int r = lower_bound(nu.begin(), nu.end(), ra[i] + 1) - nu.begin() - 1, l = lower_bound(u.begin(), u.end(), i) - u.begin();
		if (l != nn && r != -1){
			if (r >= l){
				add(1, 0, m - 1, l, r, 1);
			}
		}
	}
	getmax(1);
	for (int i = 0; i < d.size() - 1; i++){
		k = nd[i + 1];
		for (int j = nd[i]; j > nd[i + 1]; j--){
			if (ok[a[j]]){
				int r = lower_bound(nu.begin(), nu.end(), j + 1) - nu.begin() - 1, l = lower_bound(u.begin(), u.end(), a[j]) - u.begin();
				if (l != nn && r != -1){
					if (r >= l){
						add(1, 0, m - 1, l, r, -1);
					}
				}
			}
		}
		for (int j = d[i]; j >= d[i + 1]; j--){
			if (!ok[j]){
				ok[j] = 1;
				int r = lower_bound(nu.begin(), nu.end(), ra[j] + 1) - nu.begin() - 1, l = lower_bound(u.begin(), u.end(), j) - u.begin();
				if (l != nn && r != -1){
					if (r >= l){
						add(1, 0, m - 1, l, r, 1);
					}
				}
			}
		}
		getmax(1);
	}
	cout << al + 1 << " " << ar + 1 << '\n';
}