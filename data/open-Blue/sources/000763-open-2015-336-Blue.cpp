#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
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

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> l >> s;
	n = s.size();
	bool a, b, c;
	a = 0, b = 0, c = 0;
	forn(i, s.size()){
		if(s[i] == 'a')
			a = 1;
		if(s[i] == 'b')
			b = 1;
		if(s[i] == 'c')
			b = 1;
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