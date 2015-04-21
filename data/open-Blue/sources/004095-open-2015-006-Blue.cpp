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
#include <ctime>

using namespace std;

unordered_map <long long, long long> dp[11];

vector <long long> now;

int ch = 0;
long long aans = (long long)1e18;

void IS_TL() {
	ch++;
	ch &= (1 << 14);

	if (ch == 0) {
		if (clock() * 2.7 > CLOCKS_PER_SEC) {
			cout << aans;
			exit(0);
		}
	}
}

long long go(long long x, int k, long long res) {
	IS_TL();
	if (!dp[k].count(x)) {
		if (k == 1) {
			dp[k][x] = (x + 1) / 2;
			aans = min(aans, (x + 1) / 2 * res);
		} else {
			long long ans = (long long)1e18;
			for(int i = 0; i < (int)now.size(); i++) {
				if (now[i] > x) {
					//break;
				}

				if (x % now[i] == 0) {
					ans = min(ans, (now[i] + 1) / 2 * go(x / now[i], k - 1, (now[i] + 1) / 2 * res));
				}
			}
			dp[k][x] = ans;
		}
	}

	return dp[k][x];
}

void gen_now(long long x) {
	for (long long i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			now.push_back(i);
			now.push_back(x / i);
		}
	}

	sort(now.begin(), now.end());
}

int main() {
	long long x;

	//cin >> x;
	x = 13082761331670030 / 43;

	gen_now(x);

	int k;

	//cin >> k;
	k = 10;

	cout << go(x, k, 1) << endl;
	cout << (double)clock() / CLOCKS_PER_SEC << endl;

	return 0;
}
