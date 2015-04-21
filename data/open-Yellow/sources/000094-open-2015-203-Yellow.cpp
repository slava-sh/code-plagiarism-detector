#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int pos, col;
		cin >> pos >> col;
		a[pos - 1] = col;
		int ans = 1;
		for (int q = 1; q < N; q++)
		{
			if (a[q] != a[q - 1])
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
