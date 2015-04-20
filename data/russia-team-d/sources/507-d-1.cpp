#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define TASKNAME "fence"

using namespace std;

const int maxn = 3*1e5+2;

bool check(int x, vector <int> & A, int k)
{
	ll done = 0;
	int n = int(A.size());

	for (int i = 0; i < n; i++)
	{
		if (done + x <= A[i])
			done = A[i];
		else
			done += x;
	}
	return done <= k;
}


int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector <int> A(n);
	int l = 0, r = int(1e9) + 1;

	for (int i = 0; i < n; i++)
		cin >> A[i], r = min(r, A[i] + 1);
	sort(A.begin(), A.end());

	//cout << check(50, A, k) << endl;

	while (r - l > 1)
	{
		int m = (l + r) / 2;

		if (check(m, A, k))
			l = m;
		else
			r = m;
	}
	cout << l << '\n';
	return 0;
}