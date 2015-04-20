#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define LLD "%I64d"

#define FILENAME "sochi"

const int maxn = 100005;

int a[maxn];
int n, d;

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	sort(a, a + n);
	reverse(a, a + n);
	int kv = 0;
	int kvall = 0;
	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 3 * d)
		{
			answer += a[i] - 2 * d;
			kvall++;
		}
		else if (a[i] >= 2*d && kv < 2)
		{
			kv++;
			answer += a[i] - d;
		}
	}
	if (kvall + kv > 0) answer += (2 - kv) * d;
	else answer = 0;
	cout << max(answer, (ll)a[0]) << endl;

	return 0;
}