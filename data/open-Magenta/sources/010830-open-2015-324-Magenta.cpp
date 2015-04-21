#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <list>
#include <bitset>
#include <cstring>
#include <string>
// C++11 Headers
#include <tuple>
#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

#define ll long long

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

const char moves[4] = {'U', 'L', 'D', 'R'};
const char MLG_moves[4] = {'U', 'L', 'D', 'R'};
int cnt = 0;
int pos = 0;

int CNT = 0;

void check() {
	cout.flush();
	char c;
	cin >> c;
	if (c != 'N')
		exit(0);
}

int main() {
	for (int i = 0;;i++) {
		if (i % 2 == 0) cnt++;
		
		if (i >= 16) {
			if (pos % 2 == 0) CNT++;
			if (CNT > 5) CNT = 1;
			pos++;
			for (int j = 0; j < 16 * CNT; j++) {
				cout << MLG_moves[(pos) % 4] << '\n';
				check();
			}
			cnt = 0;
			i = 0;
		}
		
		for (int j = 0; j < cnt; j++) {
			cout << moves[i % 4] << '\n';
			check();
		}
	}
		
	return 0;
}
