#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);

	if (n == 1){
		cout << m / 4 + (m % 4 == 3);
		return 0;
	}

	if (n == 2){
		cout << 0;
		return 0;
	}

	cout << 1;
	return 0;
}