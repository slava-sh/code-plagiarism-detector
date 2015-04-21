#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)
const int infi = 1e9 + 7;

string s;
int l, n;

void F(int x){
	if(s.size() % x == 0 && n >= x){
		for(int i = 0; i < n; i += x){
			forn(j, x){
				if(s[j] != s[i + j])
					return;
			}
		}
		cout << "1\n";
		forn(i, x)
			cout << s[i];
		exit(0);
	}
}

vector<ull> P(1, 1), Z(1);

ull gh(int l, int r){
	return Z[r] - Z[l - 1] * P[r - l + 1];
}

void Fu(int x, int y){
	if(n >= x + y){
		string a, b;
		forn(i, x)
			a.push_back(s[i]);
		forn(i, y)
			b.push_back(s[i + x]);
		ull h1, h2;
		h1 = h2 = 0;
		forn(i, x){
			h1 *= 31;
			h1 += a[i] - 'a' + 1;
		}
		forn(i, y){
			h2 *= 31;
			h2 += b[i] - 'a' + 1;
		}
		vector<bool> W(n + 1);
		W[0] = 1;
		fornn(i, 1, n + 1){
			if(i - x >= 0 && W[i - x] && gh(i - x + 1, i) == h1){
				W[i] = 1;
			}
			if(i - y >= 0 && W[i - y] && gh(i - y + 1, i) == h2){
				W[i] = 1;
			}
		}
		if(!W[n])
			return;
		cout << "2\n" << a << '\n' << b;
		exit(0);
	}
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	forn(i, 20005){
		P.push_back(P.back() * 31);
	}
	cin >> l >> s;
	n = s.size();
	forn(i, n){
		Z.push_back(Z.back() * 31 + (s[i] - 'a' + 1));
	}
	bool a, b, c;
	a = 0, b = 0, c = 0;
	forn(i, s.size()){
		if(s[i] == 'a')
			a = 1;
		if(s[i] == 'b')
			b = 1;
		if(s[i] == 'c')
			c = 1;
	}
	if(a && !b && !c){
		cout << "1\na";
		return 0;
	}
	if(!a && b && !c){
		cout << "1\nb";
		return 0;
	}
	if(!a && !b && c){
		cout << "1\nc";
		return 0;
	}
	if(a && b && c){
		fornn(i, 1, l + 1){
			F(i);
		}
		fornn(i, 1, l + 1){
			fornn(j, 1, l + 1){
				Fu(i, j);
			}
		}
		cout << "3\na\nb\nc";
	}
	else{
		fornn(i, 1, l + 1){
			F(i);
		}
		if(a && b){
			cout << "2\na\nb";
			return 0;
		}
		if(a && c){
			cout << "2\na\nc";
			return 0;
		}
		if(b && c){
			cout << "2\nc\nb";
			return 0;
		}
	}
}