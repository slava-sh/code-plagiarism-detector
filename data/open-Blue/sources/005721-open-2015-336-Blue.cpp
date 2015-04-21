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
const ull mod = 1e9 + 7;

string s;
int l, n;
vector<ull> P(1, 1), Z(1);
vector<ull> P2(1, 1), Z2(1);

ull gh(int l, int r){
	return Z[r] - Z[l - 1] * P[r - l + 1];
}

ull gh2(int l, int r){
	return ((Z2[r] - Z2[l - 1] * P2[r - l + 1]) % mod + mod) % mod;
}


void F(int x){
	if(s.size() % x == 0 && n >= x){
		for(int i = x; i <= n; i += x){
			if(gh(1, x) != gh(i - x + 1, i))
				return;
		}
		cout << "1\n";
		forn(i, x)
			cout << s[i];
		exit(0);
	}
}


ull h1, h2;
ull h12, h22;

void Fu(string &a, string &b){
	int x = a.size(), y = b.size();
	if(n >= x + y){
		int iw = 0;
		for(iw = 0; iw < n;){
			if(iw + x <= n && gh(iw + 1, iw + x) == h1 && gh2(iw + 1, iw + x) == h12){
				iw += x;
				continue;
			}
			if(iw + y <= n && gh(iw + 1, iw + y) == h2 && gh2(iw + 1, iw + y) == h22){
				iw += y;
				continue;
			}
			return;
		}
		if(iw != n)
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
		P2.push_back((P2.back() * 29) % mod);
	}
	cin >> l >> s;
	n = s.size();
	forn(i, n){
		Z.push_back(Z.back() * 31 + (s[i] - 'a' + 1));
		Z2.push_back((Z2.back() * 29 + (s[i] - 'a' + 1)) % mod);
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
		string a;
		if(l > n / 2 + 5){
			cout << "2\n";
			forn(i, n / 2)
				cout << s[i];
			cout << '\n';
			fornn(i, n / 2, n)
				cout << s[i];
			return 0;
		}
		fornn(i, 1, l + 1){
			a.push_back(s[i - 1]);
			h1 *= 31;
			h1 += s[i - 1] - 'a' + 1;
			h2 = 0;

			h12 *= 29;
			h12 += s[i - 1] - 'a' + 1;
			h12 %= mod;
			h22 = 0;

			int x = a.size(), y = 0;
			string b;
			for(int i = x; i <= n; i += x){
				if(gh(1, x) != gh(i - x + 1, i)){
					y = i - x;
					break;
				}
			}
			for(int k = 1; k <= l && y + k <= n; k++){
				b.push_back(s[y + k - 1]);
				h2 *= 31;
				h2 += s[y + k - 1] - 'a' + 1;

				h22 *= 29;
				h22 += s[y + k - 1] - 'a' + 1;
				h22 %= mod;

				Fu(a, b);
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