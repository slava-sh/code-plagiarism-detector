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

static int m1[3000], m2[3000], m3[3000][3000], m4[3000][3000];

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
	ll a = 0, b = n, c, tm, cl;
	while (a < b){
        c = (a + b + 1) / 2;
        tm = n;
        cl = 0;
        for (ll i = c; i <= tm;){
            if (tm % i == 0){
                tm /= i;
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
	for (ll i = a; i <= n;){
        if (n % i == 0){
            n /= i;
            vc.push_back(i);
			if (i == 1 && vc.size() > k + 2)
				++i;
        }
	}
	for (int i = k; i < vc.size(); ++i)
        vc[0] *= vc[i];
    ll res = 1;
    for (int i = 0; i < k; ++i)
        res *= (vc[i] + 1) / 2;
    cout << res << endl;
	system("pause");
	return 0;
}
