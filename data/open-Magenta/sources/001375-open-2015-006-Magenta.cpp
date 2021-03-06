#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <ctime>

using namespace std;

#define U printf("U\n");
#define D printf("D\n");
#define L printf("L\n");
#define R printf("R\n");

int main() {
	int x = 301;

	while (true) {
		bool st = true;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				if (st) {
					U;
				} else {
					D;
				}
				fflush(stdout);
				char c;

				scanf("\n%c", &c);

				if (c != 'N') {
					exit(0);
				}
			}

			st = !st;

			if (i != x - 1) {
				R;
				fflush(stdout);
			}
		}
	}

	return 0;
}
