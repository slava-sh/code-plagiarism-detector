#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int v[100002];


int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("fence.in", "r", stdin);freopen("fence.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int used = 0;
	int not_used = k;
	int need = k / n;
	int ans = k;
	int people = n;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v + n);
	for(int i = 0; i < n; i++) {
		need = not_used / people;
		ans = min(ans, need);
		people--;
		int a = v[i];
		if(a <= need) {
			not_used -= a;
			used += a;
			ans = min(ans, a);
		}else{
			if(need + used >= a) {
				not_used -= need;
				used += need;
			}else{
				not_used -= a - used;
				used += a - used;
			}
		}
	}
	cout << ans;
	return 0;
}