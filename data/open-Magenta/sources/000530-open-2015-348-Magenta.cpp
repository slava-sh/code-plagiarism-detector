#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define localn
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 510

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



int main(){
#ifdef local
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	char tp[3];
	for (int i = 0;; i++){
		if (i == N){
			printf("D\n");
			fflush(stdout);
			scanf("%s", &tp);
			if (tp[0] == 'Y' || tp[0] == 'E'){
				return 0;
			}
			printf("R\n");
			fflush(stdout);
			scanf("%s", &tp);
			if (tp[0] == 'Y' || tp[0] == 'E'){
				return 0;
			}
			i = -1;
		}
		else {
			if (i & 1){
				printf("R\n");
			}
			else {
				printf("U\n");
			}
			fflush(stdout);
			scanf("%s", &tp);
			if (tp[0] == 'Y' || tp[0] == 'E'){
				return 0;
			}
		}
	}

	return 0;
}