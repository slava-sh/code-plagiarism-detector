#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pii pair<int,int>

int ANS;
vector<bool> u;
vector<vector<int> > a;

void dfs(int i, int j, int g){
	u[i] = 1;
	u[j] = 1;	
	for (int q = 0; q < a[i].size(); q++){
		if (!u[a[i][q]]){
			for (int w = 0; w < a[j].size(); w++){
				if (!u[a[j][w]] && a[j][w] != a[i][q]){
					dfs(a[i][q], a[j][w], g + 1);
				}
			}
		}
	}
	for (int q = 0; q < a[j].size(); q++){
		if (!u[a[j][q]]){
			for (int w = 0; w < a[i].size(); w++){
				if (!u[a[i][w]] && a[i][w] != a[j][q]){
					dfs(a[i][w], a[j][q], g + 1);
				}
			}
		}
	}
	ANS = max(g, ANS);
	u[i] = 0;
	u[j] = 0;
}


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);	
	ANS = 0;
	int n;
	cin >> n;
	u.resize(n);
	a.resize(n);
	

	for(int i = 0; i < n - 1; i++){
		int q, w;
		cin >> q >> w;
		q--;
		w--;
		a[q].pb(w);
		a[w].pb(q);
	}
	int v0, v1;
	cin >> v0 >> v1;
	v0--;
	v1--;

	dfs(v0, v1, 0);
	
	cout << ANS + 1;
}
