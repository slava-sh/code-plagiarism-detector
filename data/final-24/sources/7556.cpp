#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long


using namespace std;

vector <ll> levels;

bool cmp(ll a, ll b) {
	return b < a;
}

int main() {
	ll n, z;
	int k;

	cin >> n >> k;
	z = n;

	ll _2 = 0;
	while ((n % 2 == 0) && (n > 1)) {
		_2++;
		n /= 2;
	}


	for (int i = 2; i * i <= n; i++) {
		if ((n % i == 0) && (n > 1)) {
			levels.push_back(i);
			n /= i;
		}
	}

	if (n != 1)
		levels.push_back(n);
	
	sort(levels.begin(), levels.end(), cmp);
	n = z;

	while (_2 > 0 && k > 1) {
		n /= 2;
		z = z / 2;
		k--;
		_2--;
	}
	for (int i = 0; i < levels.size(); i++) {
		if (levels[i] % 2 == 1 && k > 1) {
			n /= levels[i];
			z = z / (levels[i]) * (levels[i] / 2 + 1);
			k--;
		}
	}

	z = z / n * (n / 2 + n % 2);
	cout << z << endl;
}