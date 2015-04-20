#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double de;
typedef pair<de, de> pde;
typedef vector<ll> vecl;
typedef vector<pll> vecpl;
typedef string str;
typedef vector<bool> veb;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define si size

const ll INF = 1e18 + 1, maxn = 2 * (1e5 + 1);
const de eps = 1e-9;

ll n, m, i, k, j;
string s, s1, c, ans;
map <string, vector <string>> g;
vector <string> oo;
bool b = 0;

map <string, vector <string>>::iterator it;

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
#endif

	cin >> n;
	for (i=0; i<n; i++){
		cin >> c >> k;
		oo.clear();
		for (j=0; j<k; j++){
			cin >> s;
			oo.pb(s);
		}
		g[c] = oo;
	}
	cin >> m;
	for (i=0; i<m; i++){
		cin >> s;
		b = 0;
		for (it = g.begin(); it != g.end(); it++){
			if (s.find((*it).first) == 0){
				ll len = (*it).first.size();
				ans = '+' + (*it).first;
				for (j = 0; j < (*it).second.size(); j++){
					if (s.find((*it).second[j]) == len){
						ans += '(' + (*it).second[j] + ')';
						len += (*it).second[j].si();
						s1 = s.substr(len, 11-len+1);
						if (s1[0] == '0'){
							ans = "Incorrect";							
							break;
						}
						else {
							b = 1;
							if (s1.si() == 3){
								ans += s1;
							}
							if (s1.si() == 4){
								ans += s1[0]; ans += s1[1]; ans += '-'; ans += s1[2]; ans += s1[3];
							}
							if (s1.si() == 5){
								ans += s1[0]; ans += s1[1]; ans += s1[2]; ans += '-'; ans += s1[3]; ans += s1[4];
							}
							if (s1.si() == 6){
								ans += s1[0]; ans += s1[1]; ans += '-'; ans += s1[2]; ans += s1[3]; ans += '-'; ans +=  s1[4]; ans += s1[5];
							}
							if (s1.si() == 7){
								ans += s1[0]; ans += s1[1]; ans +=  s1[2]; ans += '-'; ans += s1[3]; ans += s1[4]; ans += '-'; ans +=  s1[5]; ans += s1[6];
							}
						}
					}
				}
				if (!b){
						ans = "Incorrect";
				}
			}
		}
		if (!b){
			ans = "Incorrect";
		}
		cout << ans << endl;
		ans.clear();
	}
}