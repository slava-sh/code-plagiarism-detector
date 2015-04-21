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
vector<int> P;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string s;
	int l;
	cin >> l >> s;
	bool a, b;
	a = 0, b = 0;
	forn(i, s.size()){
		if(s[i] == 'a')
			a = 1;
		if(s[i] == 'b')
			b = 1;
	}
	if(a && b)
		cout << "2\na\nb";
	else{
		if(a)
			cout << "1\na";
		else{
			if(b){
				cout << "1\nb";
			}
		}

	}
}