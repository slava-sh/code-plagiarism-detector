#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define push_back pb
#define make_pair mp
#define first fr
#define second sc


int n;
long long k;
vector<int> a;
bool can(int i){	
	int j = 1;
	long long r = a[0];
	while (j < n){
		long long y = (long long)a[j] - r - (long long)i;
		if (y > 0) r += y;
		r += (long long)i;	
		j++;
	}
	if (r > k){
		return 0;
	}
	else return 1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	cin >> n >> k;
	a.resize(n);	
	for (int i = 0; i < n; i++){
		int q;
		cin >> q;
		a[i] = q;		
	}
	sort(a.begin(), a.end());
	
	int r = min(a[0], (int)k / n);
	int l = 0;

	while (r - l > 1){
		int m = (r + l) / 2;
		if (can(m)){
			l = m;
		} else r = m;
	}
	for(int i = r; i >= l; i--){
		if (can(i)){
			cout << i;
			return 0;
		}
	}	
}