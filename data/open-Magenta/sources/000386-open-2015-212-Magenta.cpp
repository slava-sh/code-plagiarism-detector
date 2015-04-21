#pragma comment(linker, "/STACK:16777216")

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

void check() {
	char cmd;
	cin >> cmd;
	if (cmd == 'Y') {
		exit(0);
	}
	if (cmd == 'E') {
		exit(0);
	}
}

int main() {
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//#define FILE_NAME ""
	//	freopen(FILE_NAME ".in", "r", stdin);
	//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int w = 1;
	check();
	while (true) {
		cout << "R\n";
		cout.flush();
		check();
		for (int i = 0; i < w; ++i) {
			cout << "D\n";
			cout.flush();
			check();
		}
		for (int i = 0; i < w; ++i) {
			cout << "L\n";
			cout.flush();
			check();
		}
		cout << "D\n";
		cout.flush();
		check();
		++w;
		for (int i = 0; i < w; ++i) {
			cout << "R\n";
			cout.flush();
			check();
		}
		for (int i = 0; i < w; ++i) {
			cout << "U\n";
			cout.flush();
			check();
		}
		++w;
	}

	return 0;
}