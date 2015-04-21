#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> vec;

int main () {
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			vec.push_back(i);
			if (i * i != n) {
				vec.push_back(n / i);
			}
		}
	}
	sort(vec.begin(), vec.end());
	long long ans = 1;
	for (int i = 1; i < vec.size(); i++) {
		if (k == 1) {
			ans *= (n / 2 + n % 2);
			break;
		}
		while (n % vec[i] == 0 && k > 1) {
			k--;
			n /= vec[i];
			ans *= (vec[i] / 2 + vec[i] % 2);
		}
	}
	cout << ans;
	return 0;
}