#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>

#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
#define S second
#define F first


const int INF = int(1e9) + 7;
const ll INFll = int(1e18) + 7;
const ull md = 97;
const ull m2 = 239;

using namespace std;

ll n, k, ans = 1, got = 0;



int main(){
//	ifstream cin ("test.in");
	cin >> n >> k;
	for (ll i = 2; i * i <= n; i++){
		if (n % i == 0){
			n /= i;
			got++;
			ans *=((i + 1) / 2);	
			i--;
			if (got == k - 1){
				ans *= ((n + 1) / 2);
				cout << ans << '\n';
				return 0;
			}
		}
	}
}