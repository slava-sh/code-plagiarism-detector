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


using namespace std;



ll n, k, c, d, a[200005], b[200005], ans = INFll, sum[200005], now;



int main(){
	srand(time(NULL));
//	ifstream cin ("test.in");
	
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		now += (b[i] - a[i]) * d;
		if (i){
			sum[i] = a[i] - b[i - 1];
			now += sum[i] * d;
		}
	}
	sort(sum + 1, sum + n);
	reverse(sum + 1, sum + n);
	ans = now;
	int p = 0;
	for (int i = 1; p < n; i++){
		int f = (k - 1) * i + (i - 1);
		if (i > 1) now += c;
		while (p < n && p <= f){
			now -= sum[p] * d;
			p++;
		}
		ans = min(ans, now);
	}
	cout << ans << '\n';

}