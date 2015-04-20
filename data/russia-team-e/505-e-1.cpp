#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

map<string, int> country, oper[111];
int n, m;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++){
		string code, code2;
		int k;
		cin >> code >> k;
		country[code] = i;
		for (int j = 0; j < k; j++){
			cin >> code2;
			oper[i][code2] = 1;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++){
		char ok = false;
		string s;
		cin >> s;

		for (int j = 1; j <= 3; j++){
			for (int z = 3; z <= 5; z++){
				if (ok) break;
				string code = s.substr(0, j), code2 = s.substr(j, z);
				if (country.count(code)){
					if (oper[country[code]].count(code2)){
						if (s[j + z] == '0') continue;
						cout << "+" << code << "(" << code2 << ")";
						s = s.substr(j + z, s.length() - j - z);
						if (s.length() == 3){
							cout << s;
						}
						if (s.length() == 4){
							cout << s.substr(0, 2) << "-" << s.substr(2, 2);
						}
						if (s.length() == 5){
							cout << s.substr(0, 3) << "-" << s.substr(3, 2);
						}
						if (s.length() == 6){
							cout << s.substr(0, 2) << "-" << s.substr(2, 2) << "-" << s.substr(4, 2);
						}
						if (s.length() == 7){
							cout << s.substr(0, 3) << "-" << s.substr(3, 2) << "-" << s.substr(5, 2);
						}
						cout << "\n";
						ok = true;
						break;
					}
				}
			}
		}
		if (!ok) cout << "Incorrect\n";
	}
	return 0;
}