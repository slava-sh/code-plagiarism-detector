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

const ll INF = 1e18 + 1, maxn = 3 * (1e5 + 1);
const de eps = 1e-9;

ll n, i, j, k, m, answer, a[maxn], d, t, s, m1, m2;

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
#endif

	cin >> n >> d;
	for(i = 0; i < n; ++i){
		cin >> a[i];
		m = max(a[i], m);
	}
	for(i = 0; i < n; ++i){
		if(a[i] >= d * 3){
			s += a[i];
			t++;
		}
	}
	m2 = 2 * d;
	m1 = 2 * d;
	for(i = 0; i < n; ++i){
		if(a[i] < 3 * d && a[i] >= 2 * d){
			if(m1 < a[i]){
				m2 = max(m2, m1);
				m1 = a[i];
				continue;
			}
			if(a[i] > m2){
				m2 = a[i];
			}
		}
	}
	if(t == 0){
		cout << m;
		return 0;
	}
	answer = s - 2 * (t - 1) * d + m1 + m2 - 4 * d;
	cout << answer;
}