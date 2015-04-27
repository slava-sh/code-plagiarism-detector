#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int t[2][100001] = {0};
int v[2][100001] = {0};

int solve(int h, int rem, int k, int cur){
	int prev[2] = {-1, -1};
	int len = 100000;
	int temp = 0;

	for (int j = 0; j < k; j++){
		int ind = (rem * len) / h;
		int ost = (rem * len) % h;
		if (ost == 0){
			if (t[cur][ind] != prev[cur] && t[cur][ind] != 0){
				prev[cur] = t[cur][ind];
				temp += v[cur][ind];
			}
			else{
				temp = 0;
				break;
			}
		}
		else{
			if (t[cur][ind] != prev[cur] && t[cur][ind] != 0 && t[cur][ind + 1] != 0){
				prev[cur] = t[cur][ind];
				temp += v[cur][ind];
			}
			else{
				temp = 0;
				break;
			}
		}				
		cur = 1 - cur;
		rem += 100;
	}

	return temp;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int hl, hr, n;
	cin>>hl>>hr>>n;

	for (int i = 1; i <= n; i++){
		int vi, ai, bi;
		char ci;
		cin>>vi>>ci>>ai>>bi;
		int cur;
		if (ci == 'T'){
			cur = 0;
		}
		else{
			cur = 1;
		}
		for (int j = ai; j <= bi; j++){
			t[cur][j] = i;
			v[cur][j] = vi;
		}
	}

	int score = 0;

	for (int i = 1; i <= 100; i++){
		int h, rem, cur;

		if (i & 1){
			h = hl + hr + 100 * (i - 1);
			rem = hl;
			cur = 1;
			score = max(score, solve(h, rem, i, cur));
			h = 100 - hl + 100 - hr + 100 * (i - 1);
			rem = 100 - hl;
			cur = 0;
			score = max(score, solve(h, rem, i, cur));
		}
		else{
			h = 100 - hl + hr + 100 * (i - 1);
			rem = 100 - hl;
			cur = 0;
			score = max(score, solve(h, rem, i, cur));
			h = hl + 100 - hr + 100 * (i - 1);
			rem = hl;
			cur = 1;
			score = max(score, solve(h, rem, i, cur));
		}
	}

	cout<<score;

}