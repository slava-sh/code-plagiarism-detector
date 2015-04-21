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
const ll INFll = ll(1e18) + 7;
const ull md = 97;
const ull m2 = 239;

using namespace std;

ll n, kk, dp[1000005][11];



int main(){
//	ifstream cin ("test.in");
	cin >> n >> kk;
	for (int i = 1; i <= 1000; i++){
		dp[i][1] = (i + 1) / 2;
	}
	for (int k = 2; k <= 10; k++){
		for (int j = 1; j <= 1000; j++){
			dp[j][k] = (j + 1) / 2;
			for (int i = 2; i * i <= j; i++){
				if (j % i == 0){
					dp[j][k] = min(dp[j][k], dp[j / i][k - 1] * ((i + 1) / 2));
				}
			}
		}
	}
	cout << dp[n][kk];
	return 0;
}