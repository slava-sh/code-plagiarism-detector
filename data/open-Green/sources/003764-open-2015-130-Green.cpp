#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	ll n, k, p2 = 0;
	cin >> n >> k;
	while (n % 2 == 0){
        n /= 2;
        ++p2;
	}
	if (p2 >= k){
        cout << ((n << (p2 - k + 1)) + 1) / 2 << endl;
        return 0;
	}
	k -= p2;
	vector <ll> dl;
	for (ll i = 1; i * i <= n; ++i) if (n % i == 0){
		dl.push_back(i);
		if (i * i != n)
			dl.push_back(n / i);
	}
	sort(dl.begin(), dl.end());
	ll a = 0, b = dl.size() - 1, c, tm, cl;
	while (a < b){
        c = (a + b + 1) / 2;
        tm = n;
        cl = 0;
        for (ll i = c; i < dl.size() && dl[i] <= tm;){
            if (tm % dl[i] == 0){
                tm /= dl[i];
                cl++;
				if (cl >= k)
					break;
            }
            else
                ++i;
        }
        if (cl >= k)
            a = c;
        else
            b = c - 1;
	}
	vector <ll> vc;
	cl = 0;
	for (ll i = a; i < dl.size() && dl[i] <= n;){
        if (n % dl[i] == 0){
            n /= dl[i];
            vc.push_back(dl[i]);
			if (dl[i] == 1 && vc.size() > k + 2)
				++i;
        }
		else
			++i;
	}
	while (vc.size() < k)
		vc.push_back(1);
	a = 0;
	for (ll i = vc.size() - 1; i >= k; --i){
        vc[a] *= vc[i];
		a = (a + 1) % k;
	}
    ll res = 1;
    for (ll i = 0; i < k; ++i)
        res *= (vc[i] + 1) / 2;
    cout << res << endl;
	//system("pause");
	return 0;
}
