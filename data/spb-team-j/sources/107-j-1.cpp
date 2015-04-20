#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

#define problem "seq"
#define sort stable_sort
#define ll long long
#define INFll 1e18 + 7
#define mp make_pair
#define pb push_back
using namespace std;


ll n, nn, m = 1, h, a[200005], sum[200005], need, ans = -1;

vector <bool> tree;

void get(int v, int l, int r, int a, int b){
	if (!tree[v]) return;
	if (l >= a && r <= b) {
		tree[v] = false;
		return;
	}
	if (a > r || b < l) return;
	get(2 * v, l, (l + r) / 2, a, b);
	get(2 * v + 1, (l + r) / 2 + 1, r, a, b);
	if (tree[2 * v] || tree[2 * v + 1]) tree[v] = true;
	else tree[v] = false;
}


void push(int v){
	if (v >= 2 * m) return;
	if (!tree[v / 2])tree[v] = false;
	push(2 * v);
	push(2 * v + 1);
}

int main()
{
	ifstream cin(problem".in");
	ofstream cout(problem".out");
	cin >> n >> h;
	need = h * (h + 1) / 2;
	nn = n;
	while (nn){
		nn >>= 1;
		m <<= 1;
	}
	tree.resize(2 * m, true);
	for (int i = m; i < m + n - h + 1; i++){
		tree[i] = true;
	}

	for (int i = m + n - h + 1; i < 2 * m; i++) tree[i] = false;

	for (int i = m - 1; i > 0; i--){
		if (tree[2 * i] || tree[2 * i + 1]) tree[i] = true;
		else tree[i] = false;
	}

	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > 1) get(1, 0, m - 1, i - min(a[i], h + 1) + 2, i);
	}

	push(1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i - 1];
	}

	for (int i = 0; i < n; i++){
		if (tree[m + i]){
			if (ans == -1 || ans > (-sum[i + h] + sum[i] + need)) ans = -sum[i + h] + sum[i] + need;
		}
	}
	cout << ans << '\n';
	return 0;
}