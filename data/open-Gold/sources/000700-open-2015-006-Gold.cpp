#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int maxn = (int)2e5 + 10;

long long l[maxn], r[maxn];

int main() {
	int n;
	long long k;

	scanf("%d %lld", &n, &k);

	long long c, d;

	cin >> c >> d;

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &l[i], &r[i]);
		ans += (r[i] - l[i]) * d;
	}

	priority_queue <long long> q;

	long long now = ans;

	for (int i = 0; i < n - 1; i++) {
		now += (l[i + 1] - r[i]) * d;
		q.push(l[i + 1] - r[i]);
	}

	for (int i = 1; i < k && !q.empty(); i++) {
		now -= q.top() * d;
		q.pop();
	}

	ans = now;

	while (!q.empty()) {
		now += c;

		for (int i = 0; i < k && !q.empty(); i++) {
			now -= q.top() * d;
			q.pop();
		}

		ans = min(ans, now);
	}

	cout << ans << endl;

	return 0;
}
