#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
#define MOD 1000000007LL
#define P 5
using namespace std;

char s[1000000];
int ssize;

ll h[100000];
ll p[100000];

ll MOD_(ll x) {
	if (x >= MOD) return x % MOD;
	return x;
}

ll hsh(int l, int r) {
	ll res = h[r];
	if (l > 0) {
		res = MOD_(MOD + res - MOD_(h[l - 1] * p[r - l + 1]));
	}
	return res;
}

int ansc = 4;
int ansl[4], ansr[4];

int main(void) {
	int l;
	scanf("%d", &l);
	scanf("%s", s);
	ssize = strlen(s);
	h[0] = s[0] - 'a' + 1;
	p[0] = 1;
	for (int i = 1; i < 100000; ++i)
		p[i] = MOD_(p[i - 1] * P);
	for (int i = 1; i < ssize; ++i) {
		h[i] = MOD_(h[i - 1] * P + s[i] - 'a' + 1);
	}
	ll ch = 0;
	bool flag;
	int l_, r_;
	for (int i = 0; i < ssize; ++i) {
		if (i >= l) break;
		flag = true;
		for (int k = i + 1; k <= ssize; ) {
			if (k == ssize) {
				printf("1\n");
				for (int j = 0; j <= i; ++j)
					printf("%c", s[j]);
				printf("\n");
				return 0;
			}
			if ((k + i < ssize) && (hsh(k, k + i) == hsh(0, i))) {
				k += i + 1;
				continue;
			} else {
				if (ansc == 2) break;
				l_ = k;
				for (r_ = k; r_ < ssize; ++r_) {
					if (ansc == 2) break;
					if (r_ - l_ >= l) break;
					for (int k = r_ + 1; k <= ssize;) {
						if (k == ssize) {
							ansc = 2;
							ansl[0] = 0;
							ansr[0] = i;
							ansl[1] = l_;
							ansr[1] = r_;
							break;
						} 
						if ((k + i < ssize) && (hsh(k, k + i) == hsh(0, i))) {
							k += i + 1;
							continue;
						}
						if ((k + r_ - l_ < ssize) && (hsh(k, k + r_ - l_) == hsh(l_, r_))) {
							k += r_ - l_ + 1;
							continue;
						}
						break;
					}
				}
				break;
			}
		}
	}
	if (ansc == 4) {
		printf("3\na\nb\nc\n");
	}
	if (ansc == 2) {
		printf("2\n");
		for (int i = 0; i <= ansr[0]; ++i)
			printf("%c", s[i]);
		printf("\n");
		for (int i = ansl[1]; i <= ansr[1]; ++i)
			printf("%c", s[i]);
		printf("\n");
	}
}