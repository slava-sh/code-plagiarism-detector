#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector <long long> vec;
map <pair <long long, long long>, long long> mp;

long long ansq (long long n, long long k) {
	if (k == 1) {
		return n / 2 + n % 2;
	}
	if (mp.find(make_pair(n, k)) != mp.end()) {
		return mp[make_pair(n, k)];
	}
	long long mx = n / 2 + n % 2;
	for (long long i = 1; i < vec.size() && vec[i] <= n; i++) {
		if (n % vec[i] == 0) {
			mx = min(mx, ansq(n / vec[i], k - 1) * (vec[i] / 2 + vec[i] % 2));
		}
	}
	mp[make_pair(n, k)] = mx;
	return mx;
}

int main () {
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			vec.push_back(i);
			if (i * i != n) {
				vec.push_back(n / i);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << ansq(n, k);
	return 0;
}