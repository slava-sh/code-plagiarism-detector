#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

string sub(string s, int l, int r){
	string help;
	for(int i = l; i <= r; i++){
		help += s[i];
	}
	return help;
}

long long con(string s){
	reverse(s.begin(), s.end());
	long long ans = 0;
	int ss = s.size();
	for(int i = 0; i < ss; i++){
		ans += pow(10.0, (double)i) * (s[i] - '0');
	}
	return ans;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);	
	int n;
	cin >> n;
	map<int, vector<int> > a;

	for (int i = 0; i < n; i++){
		int c, k;
		cin >> c >> k;
		for(int j = 0; j < k; j++){
			int q;
			cin >> q;
			a[c].pb(q);
		}
	}
	int kol;
	cin >> kol;
	for (int u = 0; u < kol; u++){
		string s;
		
		cin >> s;
		if (s[0] == '0'){
			cout << "Incorrect" << endl;
			continue;
		}
		int i = 0;
		int j = 1;
		bool b = 0;
		
		while (!b && i < 3){
			bool B = 1;
			int st = con(sub(s, 0, i));			
			if (a[st].size() != 0 && B){				
				j = i + 3;
				while (j < 8 && !b && B){
					int g = con(sub(s, i + 1, j));
					string G = sub(s, i + 1, j);					
 					for (int q = 0; q < a[st].size(); q++){
						if (g == a[st][q]){
							b = 1;
							if (s[j + 1] == '0'){
								b = 0;
							}
							break;	

						}
					}		
					if (G[0] == '0'){
						i++;						
						B = 0;
					}
					if (!b) j++;
				}
				if (!b && B) i++;				
			}
			else i++;			
		}
		if (!b) cout << "Incorrect" << endl; else{
			cout << "+" << sub(s, 0, i) << '(' << sub(s, i + 1, j) << ')';
			if (11 - j - 1 == 3){
				cout << sub(s, j + 1, 10) << endl;
			}
			if (11 - j - 1 == 4){
				cout << sub(s, j + 1, j + 2) << '-' << sub(s, j + 3, j + 4) << endl;
			}
			if (11 - j - 1 == 5){
				cout << sub(s, j + 1, j + 3) << '-' << sub(s, j + 4, j + 5) << endl;
			}
			if (11 - j - 1 == 6){
				cout << sub(s, j + 1, j + 2) << '-' << sub(s, j + 3, j + 4) << '-' << sub(s, j + 5, j + 6) << endl;
			}
			if (11 - j - 1 == 7){
				cout << sub(s, j + 1, j + 3) << '-' << sub(s, j + 4, j + 5) << '-' << sub(s, j + 6, j + 7) << endl;
			}
		}
	}
}