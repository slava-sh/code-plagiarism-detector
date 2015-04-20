#include <iostream>

using namespace std;

int main()
{
	freopen("abcd.in", "rt", stdin);
	freopen("abcd.out", "wt", stdout);
	int n;
	char a, b, c, d;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		int ab = (a - '0') * 10 + (b - '0');
		int cd = (c - '0') * 10 + (d - '0');
		if ((ab * ab + cd * cd) % 7 == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}