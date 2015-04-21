#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

int n, len;
bool used[10];
char s[100500];

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d\n", &n);
	gets(s + 1);
	len = strlen(s + 1);
	memset(used, false, sizeof(used));
	for (int i = 1; i <= len; i++) used[(int)(s[i]) - (int)('a')] = true;
	int cnt = 0;
	for (int i = 0; i < 3; i++) if (used[i]) cnt++;
	if (cnt == 1) {
		for (int i = 0; i < 3; i++) if (used[i]) {
			puts("1");
			prf("%c\n", (char)(i + (int)('a')));
			return 0;
		}
	}
	if (len == n) {
		prf("1\n");
		for (int i = 1; i <= len; i++) prf("%c", s[i]);
		prf("\n");
		return 0;
	}
	if (cnt == 2) {
		puts("2");
		for (int i = 0; i < 3; i++) if (used[i]) prf("%c\n", (char)(i + (int)('a')));
		return 0;
	}
	return 0;
}