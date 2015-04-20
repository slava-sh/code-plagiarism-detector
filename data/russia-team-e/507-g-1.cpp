#include <stdio.h>
#include <iostream>
#define ll long long
#define TASKNAME "prizes"
using namespace std;

const int maxn = 3*1e5+2;

int a[maxn];

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	if (n >= 3 && m >= 3)
		cout << 1;
	else
		cout << 0;
	return 0;
}