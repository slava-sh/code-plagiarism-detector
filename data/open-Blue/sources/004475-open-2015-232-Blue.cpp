#include <iostream>
#include <fstream>
#include <string>
#include <set>
#define ll long long

using namespace std;

int a, b, c, d, L;
int nom[3];
string s;
ll H[20001];
const ll P = 1E6 + 3;
ll st[20001];

ll get_hash(int l, int r){
	if(l == 0) return H[r];
	return H[r] - H[l - 1] * st[(r - l + 1)];
}

int st_ = 0;

bool calc(int a, int b = 0){
	set<int> se;
	int x = 0;
	while(x + a <= s.size() && get_hash(0, a - 1) == get_hash(x, x + a - 1))
		x += a;
	st_ = x;
	se.insert(x);
	while(!se.empty()){
		int x = *se.begin();
		if(x == s.size()) return 1;
		se.erase(se.begin());
		if(x + a <= s.size() && get_hash(0, a - 1) == get_hash(x, x + a - 1))
			se.insert(x + a);
		if(b != 0 && x + b <= s.size() && get_hash(st_, st_ + b - 1) == get_hash(x, x + b - 1))
			se.insert(x + b);
	}
	return 0;
}

int main(){
	cin >> L;
	cin >> s;
	L = min(L, (int)s.size());
	st[0] = 1;
	for(int i = 1; i < s.size(); ++i)
		st[i] = st[i - 1] * P;
	for(int i = 0; i < s.size(); ++i)
		nom[s[i] - 'a']++;
	int N = 0;
	for(int i = 0; i < 3; ++i)
		if(nom[i] > 0) ++N;
	if(N == 1){
		cout << 1 << "\n";
		for(int i = 0; i < 3; ++i)
			if(nom[i] > 0) cout << (char)(i + 'a');
	}else{
		H[0] = s[0];
		for(int i = 1; i < s.size(); ++i)
			H[i] = H[i - 1] * P + (ll)s[i];
		for(int i = 1; i <= L; ++i){
			if(calc(i)){
				cout << 1 << "\n";
				for(int q = 0; q < i; ++q)
					cout << s[q];
				return 0;
			}
			for(int q = 1; q <= L && q + i <= s.size(); ++q)
				if(calc(i, q)){
					cout << "2\n";
					for(int z = 0; z < i; ++z)
						cout << s[z];
					cout << "\n";
					for(int z = st_; z < st_ + q; ++z)
						cout << s[z];
					return 0;
				}
		}
		if(N == 2){
			cout << "2\n";
			for(int i = 0; i < 3; ++i)
				if(nom[i] > 0) cout << (char)(i + 'a') << "\n";
		}else cout << "3\na\nb\nc\n";
	}
}