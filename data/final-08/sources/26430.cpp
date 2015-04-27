#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <utility>
#include <numeric>
#include <memory>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <functional>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <bitset>

#define X first
#define Y second
#define LOW(x) ((x) & -(x))
#define SQR(x) ((x) * (x))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;

const int MAXN = 100 + 10;

int n, d, t1, t2;
double a[MAXN], ans = -1;

int main(int argc, char* argv[])
{
	cin >> n;
	for (int i = 0; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i <= n / 2; ++i)
		for (int j = (n + 1) / 2; j <= n; ++j)
		{
			d = __gcd(n - 2 * i, 2 * j - n);
			if (d == 0)
			{
				if (a[i] > ans) ans = a[i];
			}
			else
			{
				t1 = (2 * j - n) / d;
				t2 = (n - 2 * i) / d;
				if ((t1 * a[i] + t2 * a[j]) / (t1 + t2) > ans)
					ans = (t1 * a[i] + t2 * a[j]) / (t1 + t2);
			}
		}
	cout << setprecision(9) << fixed << ans << endl;
}
