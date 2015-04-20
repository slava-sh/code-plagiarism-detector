#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	long long l1, l2;
	cin >> l1 >> l2;
	long long ans, L1, L2;
	L1 = min(l1, l2);
	L2 = max(l1, l2);
	if (L1 >= 3)
		ans = 1;
	if (L1 == 1)
		ans = (L2 + 1) / 4;
	if (L1 == 2)
		ans = 0;
	cout << ans << endl;
	return 0;
}