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
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

mt19937_64 mt;

int l;
string s;

bool check1(){
	l = min((int)s.size(), l);
	vector<int> zfunc(s.size(), 0);
	s.push_back('*');
	int border = 1, pborder = 0;
	for(int i = 1; i <= l; i++){
		border = max(border, i);
		zfunc[i] = min(border - i, zfunc[i - pborder]);
		if(zfunc[i] + i >= border){
			while(s[i + zfunc[i]] == s[zfunc[i]]){
				zfunc[i]++;
				border++;
			}
		}
		if(!(int(s.size() - 1) % i) && border >= s.size() - 1){
			cout << "1\n" << s.substr(0, i);
			exit(0);
		}
	}
	return false;
}

bool check2(){
	return false;
}

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
	cin >> l >> s;
	for(int i = 0; i < s.size(); i++){
		used[s[i] - 'a'] = true;
	}
	int summ = int(used[0]) + int(used[1]) + int(used[2]);
	if(summ >= 2){
		check1();
	}
	if(summ == 3){
		check2();
	}
	cout << summ << "\n";
	for(int i = 0; i < 3; i++){
		if(used[i]){
			cout << char(i + 'a') << "\n";
		}
	}
	return 0;
}