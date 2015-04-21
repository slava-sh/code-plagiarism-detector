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
bool used[10]; 
char s[100500], ss[100500], ps[100500];
vector < string > sl;
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

int gcd(int a, int b) {
	while (a > 0 && b > 0) 
		if (a > b) a %= b;
			else b %= a;
	return a + b;
}

void p_foo(int need) {
	pi[1] = 0;
	for (int i = 2; i <= plen; i++) {
		pi[i] = pi[i - 1];
		while (true) {
			if (pi[i] == 0) {
				if (ps[1] == ps[i]) pi[i]++;
				break;
			}
			if (ps[pi[i] + 1] == ps[i]) {
				pi[i]++;
				break;
			}
			pi[i] = pi[pi[i]];
		}
	}
	int i = need + 2;
	slen = 0;
	gn = n;
	int last = -1;
	sl.clear();
	while (true) {
		if (i > plen) break;
		if (i + need - 1 <= plen) {
			if (pi[i + need - 1] == need) {
				i += need;
				last = -1;
				continue;
			}
		}
		if (last == -1) sl.pb(""), last = i;
		sl[(int)sl.size() - 1] += ps[i++];
	}
	for (int i = 0; i < sl.size(); i++) for (int j = 0; j < sl[i].size(); j++) ss[++slen] = sl[i][j];
}	
               
int tryOne_() {
	int pos;
	for (int i = 1; i <= n; i++) {
		pos = 0;
		for (size_t j = 0; j < sl.size(); j++) if ((int)sl[j].size() % i != 0) { pos = -1; break; }
		if (pos == -1) continue;
		pos = 1;
		for (int j = i + 1; j <= slen; j++) {
			if (ss[j] != ss[pos]) {
				pos = -1;
				break;
			} else pos++;
		}
		if (pos > 0) return i;
	}	
	return -1;
}
	

void tryTwo() {
	int res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) ps[j] = s[j];
		ps[i + 1] = '#';
		for (int j = 1; j <= len; j++) ps[i + j + 1] = s[j];
		plen = i + 1 + len;
		p_foo(i);
		res = tryOne_();
		if (res != -1) {
			prf("2\n");
			for (int j = 1; j <= i; j++) prf("%c", s[j]);
			puts("");
			for (int j = 1; j <= res; j++) prf("%c", ss[j]);
			puts("");
			exit(0);
		}
	}
}

string ll, rr, gs, os, mos;

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
	string os = "";
	for (int i = 1; i <= len; i++) os += s[i];
	for (int i = 1; i <= n; i++) {
		ll = "", rr = "";
		gs = os;
		for (int j = 0; j < i; j++) ll += s[i];
		while (true) {
			int f = gs.find(ll);
			if (f == 0) {
				gs.erase(0, i);
				continue;
			} else {
				for (int j = 1; j <= n; j++) {
					if (j >= (int)gs.size()) break;
					rr += gs[j - 1];
					mos = gs;
					if (solve()) {
						cout << 2 << "\n" << ll << "\n" << rr << "\n";
						exit(0);
					}
					gs = mos;
				}
				break;
			}
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
	if (len <= 1000 && n <= 100) {
		brute();        
		prf("3\na\nb\nc\n");
		return 0;
	}                          
	tryTwo();
	prf("3\na\nb\nc\n");	            
	return 0;
}