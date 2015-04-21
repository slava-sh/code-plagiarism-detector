#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

long long n;
long long tn;
vector<long long> posl;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;

	cin >> n >> k;
	k--;
	tn = n;

	int countDel = 0;
	long long ans = 0;

	for (long long i = 2; countDel < k && i < sqrt((long double)tn) + 1; ++i) {
		if (n % i == 0) {
			posl.push_back(i);
			n /= i;
			countDel++;

			while (countDel < k && n % i == 0) {
				posl.push_back(i);
				n /= i;
				countDel++;
			}
		}
	}
	
	ans = (n + 1) / 2;
	for (int i = (int)posl.size() - 1; i >= 0; --i) {
		ans *= (posl[i] + 1) / 2;
	}

	cout << ans << endl;

	return 0;
}