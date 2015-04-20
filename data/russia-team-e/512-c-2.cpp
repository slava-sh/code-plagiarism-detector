#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


vector < vector <int> > vv;

bool used[200002], m[200002];

int n, group1, group2, dis[200002];

void dfs(int v) {
	used[v] = true;
	if(vv[v].size() == 1)
		dis[v] = 0;
	if(group2 == v) {
		m[v] = true;
		dis[v] = 0;
	}
	for(int i = 0; i < vv[v].size(); i++) {
		if(!used[vv[v][i]]) {
			dfs(vv[v][i]);
			if(m[vv[v][i]]) {
				m[v] = true;
			}else{
				dis[v] = max(dis[vv[v][i]] + 1, dis[v]);
			}
		}
	}
}

vector <int> a;

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("dwarfs.in", "r", stdin);freopen("dwarfs.out", "w", stdout);
	cin >> n;
	vv.resize(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		vv[from].push_back(to);
		vv[to].push_back(from);
	}
	cin >> group1 >> group2;
	dfs(group1);
	for(int i = 1; i <= n; i++) {
		if(m[i])
			a.push_back(dis[i]);
	}
	vector<int> vecr, vecl, sumv;
	vecr.resize(a.size());
	vecl.resize(a.size());
	sumv.resize(a.size(),2);
	vecl[0] = a[0] + 1;
	for(int i = 1; i < a.size(); i++){
		vecl[i] = i + a[i] + 1;
		if(vecl[i] <= vecl[i - 1]){
			sumv[i]--;
			vecl[i] = vecl[i - 1];
		}
	}
	vecr[a.size() - 1] = a[a.size() - 1] + 1;
	for(int i = a.size() - 2; i >= 0; i--){
		vecr[i] = a.size() - i + a[i];
		if(vecr[i] <= vecr[i + 1]){
			sumv[i]--;
			vecr[i] = vecr[i + 1];
		}
	}
	int mx = 0;
	for(int i = 0; i < a.size(); i++){
		if(sumv[i] != 2){
			mx = max(mx, min(vecl[i], vecr[i]));
		} else {
			int t = 0;
			if(i != 0){
				t = max(t, min(vecl[i - 1], vecr[i]));
			}
			if(i != a.size() - 1){
				t = max(t, min(vecr[i + 1], vecl[i]));
			}
			mx = max(mx, t);
		}
	}
	cout << mx;
	return 0;
}