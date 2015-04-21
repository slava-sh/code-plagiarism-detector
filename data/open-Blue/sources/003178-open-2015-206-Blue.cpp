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

int n, len, pn;
bool used[10];
int z[100500];
char s[100500];

void calcZ() {
	memset(z, 0, sizeof(z));
	for (int i = 1, l = 0, r = 0; i < len; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - 1]);
		while (i + z[i] < len && s[z[i] + 1] == s[i + z[i] + 1])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	for (int i = len; i >= 1; --i) z[i] = z[i - 1];
}	
	

int tryOne() {
	int pos;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) continue;
		pos = i + 1;
		while (true) {
			if (pos > len) break;
			if (z[pos] < i) {
				pos = -1;
				break;
			} 
			pos = pos + i;
		}
		if (pos > 0) return i;
	}
	return -1;
}
	

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
	if (len == n) {    
		prf("1\n");
		puts(s + 1);
		return 0;
	} 
	calcZ();
	pn = tryOne();
	if (pn != -1) {
		prf("1\n");
		for (int i = 1; i <= pn; i++) prf("%c", s[i]);
		puts("");
		return 0;
	} 
	if (cnt <= 2) {
		prf("%d\n", cnt);
		for (int i = 0; i < 3; i++) if (used[i]) {
			prf("%c\n", (char)(i + (int)('a')));
		}
		return 0;
	}	
	return 0;
}