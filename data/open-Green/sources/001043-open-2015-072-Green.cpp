#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <long long> a, b;
	long long n, k;
	cin >> n >> k;
	for (long long i = 2; n > 1; ++i)
		while (n % i == 0) {
			if (i % 2 == 0)
				a.push_back(i);
			else
				b.push_back(i);
			n /= i;
		}
	while (a.size() + b.size() > k && b.size() > 0) {
		if (a.size() == 0)
			b[0] *= b.back();
		else
			a[0] *= b.back();
		b.pop_back();
	}
	while (a.size() > k) {
		a[0] *= a.back();
		a.pop_back();
	}
	long long ans = 1;
	for (int i = 0; i < a.size(); ++i)
		ans *= a[i] / 2;
	for (int i = 0; i < b.size(); ++i)
		ans *= b[i] / 2 + 1;
	cout << ans << endl;
	cin >> n;
	return 0;
}