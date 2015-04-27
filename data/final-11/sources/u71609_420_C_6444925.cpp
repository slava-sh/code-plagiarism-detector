#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int N = (int) 3e5;
int x[N], y[N], cnt[N], n, p;
vector<int> appear[N];

struct FenwickTree {
	vector<int> data;

	FenwickTree(int n): data (n + 1) {}

	void update(int pos, int v) {
		for(pos = n - pos - 1; pos < n; pos |= pos + 1) data[pos] += v;
	}

	int get(int pos) {
		int res = 0;
		for(pos = n - pos - 1; pos >= 0; pos -= ~pos & (pos + 1)) res += data[pos];
		return res;
	}
};

int main() {
	cin >> n >> p;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		++cnt[--x[i]];
		++cnt[--y[i]];
		appear[x[i]].push_back(i);
		appear[y[i]].push_back(i);
	}
	long long res = 0;
	FenwickTree tree (n + 1);
	for(int i = 0; i < n; ++i) tree.update(cnt[i], +1);
	for(int i = 0; i < n; ++i) {
		tree.update(cnt[i], -1);
		map<int, int> count;
		for(int j = 0; j < (int) appear[i].size(); ++j) {
			int other = x[appear[i][j]] ^ y[appear[i][j]] ^ i;
			++count[other];
		}
		set<int> tmp;
		for(int j = 0; j < (int) appear[i].size(); ++j) {
			int other = x[appear[i][j]] ^ y[appear[i][j]] ^ i;
			if(tmp.insert(other).second) {
				if(cnt[i] + cnt[other] - count[other] >= p) ++res;
				tree.update(cnt[other], -1);
			}
		}
		res += tree.get(max(0, p - cnt[i]));
		tmp.clear();
		for(int j = 0; j < (int) appear[i].size(); ++j) {
			int other = x[appear[i][j]] ^ y[appear[i][j]] ^ i;
			if(tmp.insert(other).second) {
				tree.update(cnt[other], +1);
			}
		}
		tree.update(cnt[i], +1);
	}
	cout << res / 2;
	return 0;
}
