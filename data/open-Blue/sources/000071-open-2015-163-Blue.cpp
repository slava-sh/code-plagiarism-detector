#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <random>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

mt19937_64 mt;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	bool used[3];
	fill(used, used + 3, false);
	string s;
	cin >> s >> s;
	for(int i = 0; i < s.size(); i++){
		used[s[i] - 'a'] = true;
	}
	int summ = int(used[0]) + int(used[1]) + int(used[2]);
	cout << summ << "\n";
	for(int i = 0; i < 3; i++){
		if(used[i]){
			cout << char(i + 'a') << "\n";
		}
	}
	return 0;
}