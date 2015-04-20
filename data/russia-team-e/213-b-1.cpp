#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int r, i = 1, j = 1, n;
long long s[300010];
long long ans;

int main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    cin >> n >> r;
    for (int h = 1; h <= n; h++)
		cin >> s[h];

	while (!(j == n && s[j] - s[i] <= r))
	{
		while (s[j] - s[i] <= r || j != n)
			j++;
		if (s[j] - s[i] > r)
		{
			ans += (long long) (n - j + 1);
		    //cout << i << j << endl;
		}
		i++;
	}
	cout << ans;
	return 0;
}