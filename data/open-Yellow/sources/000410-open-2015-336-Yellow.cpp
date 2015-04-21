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
	
	int n, m;
	cin >> n;
	P.resize(n + 2);
	forn(i, n){
		cin >> P[i + 1];
	}
	P[0] = -infi;
	P[n + 1] = -infi - 1;
	int t = 0;
	fornn(i, 1, n + 1){
		if(P[i] != P[i - 1])
			t++;
	}
	cin >> m;
	forn(i, m){
		int x, c;
		cin >> x >> c;
		if(P[x] == c){
			cout << t << '\n';
			continue;
		}
		if(P[x - 1] == c && P[x + 1] == c){
			t -= 2;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(P[x] == P[x - 1] && P[x] == P[x + 1]){
			t += 2;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(c == P[x - 1] && c != P[x + 1]){
			if(P[x] != P[x + 1])
				t --;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(c != P[x - 1] && c == P[x + 1]){
			if(P[x] != P[x - 1])
				t --;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(P[x] == P[x + 1]){
			t ++;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(P[x] == P[x - 1]){
			t ++;
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		if(P[x + 1] != c && P[x - 1] != c){
			if(P[x] == P[x + 1] || P[x] == P[x - 1]){
				t++;
			}
			cout << t << '\n';
			P[x] = c;
			continue;
		}
		cout << t << '\n';
		P[x] = c;
	}
}