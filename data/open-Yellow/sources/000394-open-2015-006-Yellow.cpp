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

using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];

int main() {
	int n;

	scanf("%d", &n);
	int l = 1, r = 1;

	set <pair <pair <int, int>, int> > s;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

		if (i != 1) {
			if (v[i] == v[i - 1]) {
				r++;
			} else {
				s.insert(make_pair(make_pair(l, r), v[i - 1]));
				l = i;
				r = i;
			}
		}
	}

	s.insert(make_pair(make_pair(l, r), v[n]));

	int q;

	scanf("%d", &q);
	int ans = 0;

	for (int i = 0; i < q; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		pair <pair <int, int>, int> f = (*(--s.upper_bound(make_pair(make_pair(x, (int)2e9), -1)))), p;
		if (f.second == y) {
			printf("%d\n", (int)s.size());
			continue;
		}
		s.erase(f);

		if (f.first.first == f.first.second) {
			s.insert(make_pair(f.first, y));
		} else {
			if (x != f.first.first) {
				s.insert(make_pair(make_pair(f.first.first, x - 1), f.second));
			}

			if (x != f.first.second) {
				s.insert(make_pair(make_pair(x + 1, f.first.second), f.second));
			}

			s.insert(make_pair(make_pair(x, x), y));
		}

		set <pair <pair <int, int>, int> >::iterator it = s.lower_bound(make_pair(make_pair(x, x), -1));
		
		it++;

		if (it != s.end()) {
			if ((*it).second == y) {
				f = (*it);
				it--;
				p = (*it);
				s.erase(f);
				s.erase(p);

				s.insert(make_pair(make_pair(p.first.first, f.first.second), y));
			}
		}

		it = s.lower_bound(make_pair(make_pair(x, x), -1));

		if (it != s.begin()) {
			it--;
			if ((*it).second == y) {
				p = (*it);
				it++;
				f = (*it);
				s.erase(f);
				s.erase(p);
				s.insert(make_pair(make_pair(p.first.first, f.first.second), y));
			}
		}

		printf("%d\n", (int)s.size());
	}

	return 0;
}
