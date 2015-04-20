#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
     ll n, d;
	 cin >> n  >> d;
	 ll ans = 0;
	 vector <ll> mas;
	 ll M = 0;
	 for (int i = 0; i < n; i++)
	 {
		 ll x;
		 cin >> x;
		 M = max(M, x);
		 if (x >= 3 * d)
		 {
			 ans += x - 2 * d;
		 }
		 else
		 {
			 if (x >= 2 * d)
			 mas.push_back(x);
		 }
	 }
	 sort(mas.begin(), mas.end());
	 if (ans == 0)
	 {
		 cout << M;
		 return 0;
	 }
	 if (mas.size() >= 2)
	 {
		 cout << max( M,ans + mas[0] + mas[1] - 2 * d);
	 }
	 else
	 {
		 if (mas.size() == 1)
		 {
			 cout << max( M, ans + mas[0]);
		 }
		 else
			 cout << max ( M, ans + 2 * d);
	 }
	return 0;
}