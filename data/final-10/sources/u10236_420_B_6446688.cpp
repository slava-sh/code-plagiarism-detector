#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <ctime>
#include <stdint.h>

using namespace std;

const int MAXN = 100010;

int could[MAXN];
int state[MAXN];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(could, 0, sizeof(could));
	int q1[MAXN], q2[MAXN];
	int qq2[MAXN];
	int num = 0;
	char s[10];
	int k;
	for (int i = 0; i < m; ++i) {
		scanf("%s%d", s, &k);
		if (s[0] == '+') {
			q1[i] = 1;
		} else {
			q1[i] = 0;
		}
		q2[i] = k - 1;
	}
	memset(state, 0, sizeof(state));
	for (int i = 0; i < m; ++i) {
		if (q1[i] == 1) {
			state[q2[i]]++;
		} else if (q1[i] == 0) {
			if (state[q2[i]] > 0) {
				state[q2[i]]--;
			} else {
				qq2[num] = q2[i];
				num++;
			}
		}
	}
	memset(could, 1, sizeof(could));
	for(int i = 0; i<m; ++i){
		if(q1[i] == 0)
			could[q2[i]] = 0;
	}
	int first;
	if(num > 0)
		first = qq2[num-1];
	else
		first = q2[0];
	could[first] = 1;
	int sum = 0;
	memset(state, 0, sizeof(state));
	for(int i = num-1; i>=0; --i){
		sum++;
		state[qq2[i]]++;
	}
	for(int i = 0; i<m; ++i){
		if(q1[i] == 0){
			state[q2[i]]--;
			sum--;
			if(sum > 0)
				could[q2[i]] = 0;
		}else{
			state[q2[i]]++;
			sum++;
			if(sum == 1 && q2[i] != first){
				could[first] = 0;
			}
			if(q2[i] != first){
				could[q2[i]] = 0;
			}
		}
	}
	if(sum > 0 && state[first] == 0){
		could[first] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (could[i])
			ans++;
	}
	printf("%d\n", ans);
	if (ans > 0) {
		for (int i = 0; i < n; ++i) {
			if (could[i]) {
				printf("%d ", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}

