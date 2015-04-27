#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 1e5+10;
pii rec[MAXn];
int init[MAXn];

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		char c;
		int x;
		cin >> c >> x;
		rec[i].first = (c=='+');
		rec[i].second = x-1;
	}
	for(int i = 0; i < m; i++) {
		int v = rec[i].second;
		if(rec[i].first && init[v] == 0) 
			init[v] = -1;
		if(!rec[i].first && init[v] == 0)
			init[v] = 1;
	}
	set<int> st;
	vector<int> ans;
	for(int i = 0; i < n; i++)
		if(init[i] == 1) {
			st.insert(i);
			init[i] = 0;
		}
	init[rec[0].second] = 0;
	for(int i = 0; i < m; i++) {
		int v = rec[i].second;
		if(rec[i].first) {
			if((int)st.size() != 0) {
				init[v] = -2;
			}
			st.insert(v);
		} else {
			st.erase(v);
			if((int)st.size() != 0) {
				init[v] = -2;
			}
			if((int)st.size() == 0 && i+1 < m && rec[i+1].second != v)
				init[v] = -2;
		}
	}
	for(int i = 0; i < n; i++)
		if(init[i] == 0)
			ans.push_back(i);
	cout << ans.size() << endl;
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i]+1 << " ";
	cout << endl;
	return 0;
}
