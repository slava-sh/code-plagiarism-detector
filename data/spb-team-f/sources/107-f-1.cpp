#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

#define problem "gcm"
#define sort stable_sort
#define ll long long
#define INFll 1e18 + 7
#define mp make_pair
#define pb push_back
using namespace std;


ll gcd(ll a, ll b){
	while (a && b)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

ll a, b, d, k, ans = 0;

int main()
{
	ifstream cin(problem".in");
	ofstream cout(problem".out");
	cin >> a >> b;
	d = gcd(a, b);
	k = a * b / (d * d);
	for (ll i = 1; i * i <= k; i++){
		if (k % i == 0){
			if (gcd(i, k / i) == 1){
				ans = i;
			}
		}
	}
	cout << ans * d << " " << (k / ans) * d;
	return 0;
}