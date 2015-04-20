#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define MAXN int(1e3 + 10)
#define INF int(1e9)
using namespace std;
vector<pair<int, int> > ans;
int a[MAXN], n;

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int i = 1;
	while(i <= n && (a[i] >= i)){
		ans.push_back(make_pair(i, i));
		i++;
	}		
	cout << int(ans.size()) << "\n";
	for(int i = 0; i < int(ans.size()); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
	return 0;
}