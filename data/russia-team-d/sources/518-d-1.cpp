#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
long long k;
vector <long long> A;

bool isOk(long long x) {
	int i;
	long long p = 0;
	for (i = 0; i < n; ++i) {
		if (p + x >= A[i]) p += x;
		else p = A[i];
	}
	return p <= k;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	cin >> n >> k;

	A.resize(n);
	int i;
	for (i = 0; i < n; ++i) cin >> A[i];
	sort(A.begin(), A.end());

	long long l, m, r;
	l = 0;
	r = A[0] + 1;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (isOk(m)) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}