#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define problem "merlin"
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

ll a[100005], sum[100005], d[100005], n;

int main()
{
	ifstream cin (problem".in");
	ofstream cout (problem".out");
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++){
		d[i] = (a[i] - a[i - 1]) * (i) + d[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + a[i];
	for (int i = n - 1; i >= 0; i--){
		if (sum[i + 1] >= d[i]){
			cout << n - i - 1 << '\n';
			return 0;
		}
	}
	return 0;
}
