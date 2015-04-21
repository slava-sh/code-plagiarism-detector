#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, k, c, d;
	long long a, b, l = 0, s = 0;
	vector <long long> v;
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		s += (b - a) * d;
		if (l > 0)
			v.push_back(a - l);
		l = b;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int h = min(k - 2, (long long)v.size() - 1);
	while (true) {
		if (h == v.size() - 1)
			break;
		long long curs = 0;
		for (int i = h + 1; i <= min(h + k, (long long)v.size() - 1); ++i)
			curs += v[i] * d;
		if (curs > c) {
			h = min(h + k, (long long)v.size() - 1);
			s += c;
		}
		else
			break;
	}
	for (int i = h + 1; i < v.size(); ++i)
		s += v[i] * d;
	cout << s << endl;
	cin >> n;
	return 0;
}