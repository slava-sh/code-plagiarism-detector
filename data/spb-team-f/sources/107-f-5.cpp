
#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include <map>

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


vector < pair <ll, ll> > p[4];
ll a, b, d, k, ansa = -INFll, ansb = INFll, now = 1;
ifstream in(problem".in");
ofstream out(problem".out");
vector <ll> f;

double time1;

void get(int i, ll x)
{
	ll now = 2;
	while (x != 1)
	{
	//	out << x << "\n";
		if (!(x % now))
		{
			p[i].pb(mp(now, 0));
			ll sz = p[i].size();
			ll z = 0;
			while (!(x % now))
			{
				x /= now;
				z++;
			}
	//		out << "sz = " << sz << " " << z << "\n";
			p[i][sz - 1].second = z;
		}
		now++;
	}
}

void go(ll v){
	if (clock() - time1 > 185){
		out << ansa * d << " " << ansb * d;
		exit(0);
	}
	if (v == f.size()){
		ll l = min(now, k / now), r = max(now, k / now);
		if (r - l < ansb - ansa){
			ansa = l;
			ansb = r;
		}
		return;
	}
	go(v + 1);
	now *= f[v];
	go(v + 1);
	now /= f[v];
}


ll mult(ll a, ll b)
{
	ll k = 1;
	for (int i = 0; i < b; i++)
		k *= a;
	return k;

}

int main()
{
	time1 = clock();
	//cin >> a >> b;
	in >> a >> b;
	get(0, a);
	get(1, b);
	d = gcd(a, b);
	k = a * b / (d * d);
	get(2, d);
	map <ll, ll> primes;
//	for (int j = 0; j < 3; j++, out << "\n")
//	for (int i = 0; i < p[j].size(); i++)
//		out << p[j][i].first << " " << p[j][i].second << "\n";
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < p[j].size(); i++)
			primes[p[j][i].first] += p[j][i].second;
		for (int i = 0; i < p[2].size(); i++)
			primes[p[2][i].first] -= (2 * p[2][i].second);
	for (map <ll, ll> ::iterator i = primes.begin(); i != primes.end(); i++)
	{
		
		pair <ll, ll> x = *i;
		if (x.second)
			p[3].pb(mp(x.first, x.second));
	}

	for (int i = 0; i < p[3].size(); i++)
	{
	//	out << p[3][i].first << " " << p[3][i].second << "\n";
		f.pb(mult(p[3][i].first, p[3][i].second));
	}
	go(0);
	out << ansa * d << " " << ansb * d << '\n';


	/*d = gcd(a, b);
	k = a * b / (d * d);
	for (ll i = (ll)sqrt(1. * k) + 1; i > 0; i--){
		if (i * i > k) continue;
		if (k % i == 0){
			if (gcd(i, k / i) == 1){
				ans = i;
				cout << ans * d << " " << (k / ans) * d;
				return 0;
			}
		}
	}*/
	return 0;
}