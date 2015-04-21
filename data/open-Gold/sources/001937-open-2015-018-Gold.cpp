#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> per;
vector<long long> summs;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long n, k, c, d;

	cin >> n >> k >> c >> d;
	
	long long usedTime = 0;
	long long freeTime = 0;

	int endLast;
	int s, f;
	cin >> s >> f;
	usedTime += f - s;

	endLast = f;

	for (int i = 1; i < n; ++i) {
		cin >> s >> f;
		per.push_back(s - endLast);
		freeTime += s - endLast;
		usedTime += f - s;
		endLast = f;
	}

	stable_sort(per.begin(), per.end());
	summs.push_back(0);
	for (int i = 1; i < n; ++i) {
		summs.push_back(summs[i - 1] + per[i - 1]);
	}
	long long maxL = (n + k - 1) / k - 1;
	long long minL = 0;

	long long mS = 1e18 + 1;

	for (long long i = minL; i < maxL; ++i) {
		mS = min(mS, usedTime * d + i * c + summs[max((long long)0, n - (i + 1) * k)] * d);
	}

	/*while (maxL - minL > 1) {
		long long midL = (maxL + minL) / 2;
		long long summMn = usedTime * d + minL * c + summs[max((long long)0, n - (minL + 1) * k)] * d;
		long long summ   = usedTime * d + midL * c + summs[max((long long)0, n - (midL + 1) * k)] * d;

		if (summ <= summMn) {
			minL = midL;
		} else {
			maxL = midL;
		}
	}

	long long summMx = usedTime * d + minL * c + summs[max((long long)0, n - (minL + 1) * k)] * d;
	long long summMn = usedTime * d + maxL * c + summs[max((long long)0, n - (maxL + 1) * k)] * d;*/

	cout << mS << endl;

	return 0;
}