#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef pair< int, int > Point;
typedef set< Point > Conf;
typedef set< Conf > Confs;

#define FILENAME "virus"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	vector< Point > dp;
	dp.push_back(Point(1, 0));
	dp.push_back(Point(-1, 0));
	dp.push_back(Point(0, 1));
	dp.push_back(Point(0, -1));

	int n, m, t;
	cin >> n >> m >> t;
	Conf conf;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c = getchar();
			if (c == '*') {
				conf.insert(Point(i, j));
			}
		}
		getchar();
	}
	Confs confs;
	confs.insert(conf);
	for (int ti = 0; ti < t; ++ti) {
		Confs new_confs;
		for (auto conf = confs.begin(); conf != confs.end(); ++conf) {
			for (auto p = conf->begin(); p != conf->end(); ++p) {
				for (int di = 0; di < dp.size(); ++di) {
					Point ne(p->first + dp[di].first, p->second + dp[di].second);
					if (!(0 <= ne.first && ne.first < n && 0 <= ne.second && ne.second < m) || conf->find(ne) != conf->end()) {
						continue;
					}
					Conf new_conf(*conf);
					new_conf.insert(ne);
					new_confs.insert(new_conf);
				}
			}
		}
		confs.swap(new_confs);
		new_confs.clear();
	}
	cout << confs.size() << "\n";
	return 0;
}