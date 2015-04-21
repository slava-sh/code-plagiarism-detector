#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1000000000000000000;

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
		if (a.size() == 0) {
			long long m = 1;
			for (int i = 0; i < b.size(); ++i)
				m *= b[i] / 2 + 1;
			long long mm = INF, l, r;
			for (int i = 0; i < b.size(); ++i)
				for (int j = i + 1; j < b.size(); ++j) {
					long long cm = m;
					cm /= b[i] / 2 + 1;
					cm /= b[j] / 2 + 1;
					cm *= (b[i] * b[j]) / 2 + 1;
					if (cm < mm)
						mm = cm, l = i, r = j;
				}
			mm = b[l] * b[r];
			b[r] = b.back(), b.pop_back();
			b[l] = b.back(), b.pop_back();
			b.push_back(mm);
		} else {
			int l = -1;
			for (int i = 0; i < b.size(); ++i)
				if (l < 0 || b[i] < b[l])
					l = i;
			a[0] *= b[l];
			b[l] = b.back();
			b.pop_back();
		}
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