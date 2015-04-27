#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define re return
#define cont continue
#define xx first
#define yy second
#define y0 y63951
#define y1 y89167
#define y2 y27947
using namespace std;

template <typename T>
T sqr(T x) { re x*x; }

template <typename T>
void disp(T& x) {
	for (typename T::iterator it = x.begin(); it != x.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
}

const long long p = 1000000009;
const long long q = 257;

long long qq[20005];
long long mas[20005];

string s;
int mlen;
int n;

long long f(int l, int r) {
	re (mas[r]+p - mas[l-1]*qq[r-l+1] % p) % p;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin >> mlen;
	cin >> s;
	n = s.size();
	if (mlen >= n) { cout << 1 << '\n'; cout << s; re 0; }

	qq[0] = 1;
	for (int i = 1; i <= n; ++i) qq[i] = qq[i-1]*q % p;

	for (int i = 1; i <= n; ++i) mas[i] = (mas[i-1]*q + s[i-1]) % p;

	
	for (int a = 1; a <= mlen; ++a) {
		if (n % a != 0) cont;
		int fl = 1;
		for (int l = 1; l <= n; l += a)
			if (f(l,l+a-1) != mas[a]) {
				fl = 0;
				break; }
		if (fl) {
			cout << 1 << '\n';
			for (int i = 1; i <= a; ++i) cout << s[i-1];
			re 0;
		}
	}

	for (int a = 1; a <= mlen; ++a) {
		int st;
		for (int l = 1; l <= n; l += a)
			if (f(l,l+a-1) != mas[a]) {st = l; break; }
		
		for (int b = 1; b <= min(mlen,n+1-st); ++b) {
			int i = st;
			long long t = f(st,st+b-1);
			while (i <= n) {
				if (i+a-1 <= n && f(i,i+a-1) == mas[a]) i += a;
				else if (i+b-1 <= n && f(i,i+b-1) == t) i += b;
				else break;
			}
			if (i == n+1) {
				cout << 2 << '\n';
				for (int j = 1; j <= a; ++j) cout << s[j-1];
				cout << '\n';
				for (int j = st; j <= st+b-1; ++j) cout << s[j-1];
				re 0;
			}
		}
	}
	cout << 3 << '\n';
	cout << 'a' << '\n';
	cout << 'b' << '\n';
	cout << 'c' << '\n';






	re 0;
}
