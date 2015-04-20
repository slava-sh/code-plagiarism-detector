#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define problem "chess"
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

ll n, x, y, a[1111];
vector < pair <ll, ll> > ans;
int main()
{
	ifstream cin (problem".in");
	ofstream cout (problem".out");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	x = 1;
	y = 1;
	while ((x <= n) && (y <= a[x - 1]))
	{
		ans.pb(mp(x, y));
		x++;
		y++;
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++, cout << "\n")
		cout << ans[i].first << " " << ans[i].second;
	return 0;
}
