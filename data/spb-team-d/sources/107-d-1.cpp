#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define problem "dunes"
#define ll long long
using namespace std;

ll n, m, a[1005][3];

int main()
{
	ifstream cin (problem".in");
	ofstream cout (problem".out");
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++) cin >> a[i][j];
	}
	for (int i = 0; i < m; i++){
		ll t, ans = 0;
		cin >> t;
		for (int j = 0; j < n; j++){
			if (a[j][0] <= t && a[j][1] >= t){
				if ((t - a[j][0]) & 1) ans -= a[j][2];
				else ans += a[j][2];
			}
		}
		cout << ans << '\n';
	}


	return 0;
}
