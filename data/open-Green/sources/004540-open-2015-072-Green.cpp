#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TM = 1000000;

int main() {
	srand((unsigned int)time(0));
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
	long long ans = 1000000000000000000;
	for (int i = 0; i < TM / k; ++i) {
		vector <long long> ta = a, tb = b;
		while (ta.size() + tb.size() > k && tb.size() > 0)
			if (ta.size() > 0 && (rand() % 10 > 0 || tb.size() == 1)) {
				int cur = rand() % tb.size();
				ta[0] *= tb[cur];
				tb[cur] = tb.back();
				tb.pop_back();
			} else {
				int cur = rand() % tb.size();
				long long curv = tb[cur];
				tb[cur] = tb.back();
				tb.pop_back();
				tb[rand() % tb.size()] *= curv;
			}
		while (ta.size() > k) {
			ta[0] *= ta.back();
			ta.pop_back();
		}
		long long ca = 1;
		for (int i = 0; i < ta.size(); ++i)
			ca *= ta[i] / 2;
		for (int i = 0; i < tb.size(); ++i)
			ca *= tb[i] / 2 + 1;
		ans = min(ans, ca);
	}
	cout << ans << endl;
	cin >> n;
	return 0;
}