#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define local
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



vector<int> p;
int n;

vector<int> calc(){
	vector<int> t(n);
	for (int i = 0; i < n; i++){
		int cnt = 0;
		for (int k = i - 1; k >= 0; k--){
			if (p[k] > p[i]){
				cnt++;
			}
		}
		t[i] = cnt;
	}
	return t;
}

void print(vector<int> &q){
	for (int i = 0; i < q.size(); i++){
		cout << q[i] << " ";
	}
	cout << endl;
}

int sum(vector<int> &q){
	int res = 0;
	for (int i = 0; i < q.size(); i++){
		res += q[i];
	}
	return res;
}

int main(){
#ifdef local
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int i, k;
	cin >> n;

	if (n == 1){
		cout << "-1 -1";
		return 0;
	}

	p.resize(n);
	vector<int> t, cur_t;
	for (i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	t = calc();
	//print(t);

	vector<int> pos;

	int max_i = 0;
	for (i = 1; i < n; i++){
		if (t[i] > t[max_i]){
			pos.clear();
			pos.push_back(i);
			max_i = i;
		}
		else if (t[i] == t[max_i]){
			pos.push_back(i);
		}
	}


	int ans = sum(t), a = -1;
	for (k = 0; k < pos.size(); k++){
		max_i = pos[k];
		for (i = 0; i < max_i; i++){
			swap(p[i], p[max_i]);
			cur_t = calc();
			swap(p[i], p[max_i]);
			int cur_s = sum(cur_t);
			if (cur_s < ans){
				ans = cur_s;
				a = i;
			}
		}
	}

	if (a != -1){
		cout << a + 1 << " " << max_i + 1;
	}
	else {
		cout << "-1 -1";
	}

	return 0;
}