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


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int mn = 1000000001;
	for (int i = 0; i < n; i++){
		int q;
		cin >> q;
		mn = min(mn, q);
	}
	cout << min(mn, k / n);
}