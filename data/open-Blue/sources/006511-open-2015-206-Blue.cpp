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

int n, len, pn, plen, slen, gn;
string ll, rr, gs, os, mos;
bool used[10]; 
char s[100500];       
int pi[100500];

int tryOne() {
	int pos;
	for (int i = 1; i <= n; i++) {
		if (len % i != 0) continue;
		pos = 1;
		for (int j = i + 1; j <= len; j++) {
			if (s[j] != s[pos]) {
				pos = -1;
				break;
			} else pos++;
		}
		if (pos > 0) return i;
	}	
	return -1;
}

bool solve() {
	while (true) {
		if ((int)gs.size() == 0) break;
		int f1 = gs.find(ll);
		int f2 = gs.find(rr);
		if (f1 != 0 && f2 != 0) break;
		if (f1 == 0) gs.erase(0, (int)ll.size());
			else gs.erase(0, (int)rr.size());
	}
	return (int)gs.size() == 0;
}
	

void brute() {      
	for (int i = 1; i <= len; i++) os += s[i];
	for (int i = 1; i <= n; i++) {
		ll = rr = "";
		gs = os;
		for (int j = 0; j < i; j++) ll += s[j + 1];
		while (true) {
			int f = gs.find(ll);
			if (f == 0) gs.erase(f, (int)ll.size());
				else break;
		}
		int bo = min(n, (int)gs.size());
		mos = gs;
		for (int j = 1; j <= bo; j++) {
			rr += gs[j - 1];
			if (solve()) {
				cout << 2 << "\n" << ll << "\n" << rr << "\n";
				exit(0);
			}
			gs = mos;
		} 
	}
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
	if (len <= n) {    
		prf("1\n");
		puts(s + 1);
		return 0;
	} 
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
	if (n + n >= len) {
		prf("2\n");
		for (int i = 1; i <= n; i++) prf("%c", s[i]);
		puts("");
		for (int i = n + 1; i <= len; i++) prf("%c", s[i]);
		puts("");
		return 0;
	} 
	brute();                    
	prf("3\na\nb\nc\n");
	return 0;
}