#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double de;
typedef pair<de, de> pde;
typedef vector<ll> vecl;
typedef vector<pll> vecpl;
typedef string str;
typedef vector<bool> veb;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define si size

const ll INF = 1e18 + 1, maxn = 1e5 + 1;
const de eps = 1e-9;

ll n, i, j, k, m, answer;

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
#endif

	cin >> n >> m;
	if(n > 2 && m > 2){
		cout << 1;
		return 0;
	}
	if(n == 2 || m == 2){
		cout << 0;
		return 0;
	}
	if(m == 1){
		answer = (n + 1) / 4;
		cout << answer;
		return 0;
	}
	answer = (m + 1) / 4;
	cout << answer;
	return 0;
}