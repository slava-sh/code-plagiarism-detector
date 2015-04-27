#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5 + 10;
bool bad[MAXN];
set<int> all, av, out;
string s[MAXN];
int id[MAXN];
bool mark[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> id[i]; id[i]--;
		if (s[i][0] == '+') {
			if (i != 0 && !mark[id[i]])
				bad[id[i]] = true;
			all.insert(id[i]);
		}
		else {
			if (all.find(id[i]) == all.end())
				av.insert(id[i]);
			else
				av.erase(id[i]);
		}
		mark[id[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		if (s[i][0] == '+') {
			out.erase(id[i]);
			if ((int)av.size() > 0)
				bad[id[i]] = true;
			else {
				for (set<int>::iterator it = out.begin(); it != out.end(); it++)
					bad[*it] = true;
				out.clear();
			}
			av.insert(id[i]);
		}
		else {
			av.erase(id[i]);
			if ((int)av.size() > 0)
				bad[id[i]] = true;
			if (!bad[id[i]])
				out.insert(id[i]);
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
		if (!bad[i])
			k++;
	cout << k << endl;
	for (int i = 0; i < n; i++)
		if (!bad[i])
			cout << i + 1 << " ";
	return 0;
}
