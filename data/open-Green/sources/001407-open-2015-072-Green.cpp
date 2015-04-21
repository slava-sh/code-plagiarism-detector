#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	vector <long long> a;
	multiset <long long> b;
	long long n, k;
	cin >> n >> k;
	for (long long i = 2; n > 1; ++i)
		while (n % i == 0) {
			if (i % 2 == 0)
				a.push_back(i);
			else
				b.insert(i);
			n /= i;
		}
	while (a.size() + b.size() > k && b.size() > 0) {
		if (a.size() == 0) {
			long long q = *b.begin();
			b.erase(b.begin());
			long long w = *b.begin();
			b.erase(b.begin());
			b.insert(q * w);
		} else {
			a[0] *= *b.begin();
			b.erase(b.begin());
		}
	}
	while (a.size() > k) {
		a[0] *= a.back();
		a.pop_back();
	}
	long long ans = 1;
	for (int i = 0; i < a.size(); ++i)
		ans *= a[i] / 2;
	for (multiset <long long>::iterator cur = b.begin(); cur != b.end(); ++cur)
		ans *= *cur / 2 + 1;
	cout << ans << endl;
	cin >> n;
	return 0;
}