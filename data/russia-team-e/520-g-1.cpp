#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n;
	int m;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	if (n == 1) {
		cout << m / 3 << "\n";
	} else if (n == 2) {
		cout << "0\n";
	} else {
		cout << "1\n";
	}
}