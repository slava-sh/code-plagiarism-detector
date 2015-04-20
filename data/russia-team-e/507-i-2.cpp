#include <stdio.h>
#include <algorithm>
#include <iostream>
#define ll long long
#define TASKNAME "sochi"
using namespace std;

const int maxn = 3*1e5+2;

int a[maxn];

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

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
	cout << max(0, le - 2 * d * (cnt - 1));
	return 0;
}