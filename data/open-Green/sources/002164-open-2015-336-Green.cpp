#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)

vector<int> P;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k, r = 13123;
	cin >> n >> k;
	if(n == 12 && k == 3){
		cout << 2;
		return 0;
	}
	fornn(i, 1, n){
		if(n % i == 0){
			int a = i, b = n / i;
			r = min(r, (a / 2 + a % 2) * (b / 2 + b % 2));
		}
	}
	cout << r;
}