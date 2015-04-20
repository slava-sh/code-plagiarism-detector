#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define TASKNAME "sochi"

using namespace std;

const int maxn = 3*1e5+2;

int a[maxn];

/*bool check(int x, vector <int> & A)
{
	int done = 0;

	for (int i = 0; i < n; i++)
	{
		if (done + x < A[i])
*/

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	/*int n;
	cin >> n;
	int k;
	cin >> k;
	vector <int> A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A.begin(), A.end());

	int l = 0, r = int(1e9) + 1;

	while (r - l > 1)
	{
		int m = (l + r) / 2;

		if (check(m, A))
			l = m;
		else
			r = m;
	}
	cout << l << '\n';*/

	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	int le = 0;
	int max1=0, max2=0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 3 * d) {
			cnt++;
			le += a[i];
		} else {
			if (a[i] > d) {
				if (a[i] >= max1) {
					max2=max1;
					max1=a[i];
				}
				else if (a[i] > max2) {
					max2=a[i];
				}
			}
		}
	}
	if (max1>0)
		cnt++, le += max1;
	if (max2>0)
		cnt++, le += max2;
	
	if (cnt == 0) {
		cout << a[n-1];

	} else
		cout << max(a[n-1], le - 2 * d * (cnt - 1));

	return 0;
}