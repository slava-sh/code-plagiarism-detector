#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	int N;
	pair<int, pair<int, int> > mxx;
	cin >> N;
	vector<int> ns(N);
	for(int i = 0; i < N; i++){
		scanf("%d", &ns[i]);
	}
	for(int a = 0; a < N; a++){
		for(int b = a + 1 + (mxx.first >> 1); b < N; b++){
			if(ns[a] < ns[b]){
				continue;
			}
			int res = int(ns[a] > ns[b]);
			for(int i = a + 1; i < b; i++){
				res += int(ns[a] > ns[i]) + int(ns[i] > ns[b]) - int(ns[a] < ns[i]) - int(ns[i] < ns[b]);
			}
			if(res > mxx.first){
				mxx = make_pair(res, make_pair(a, b));
			}
		}
	}
	if(mxx.first == 0){
		cout << "-1 -1";
		return 0;
	}
	cout << mxx.second.first + 1 << " " << mxx.second.second + 1;
	return 0;
}