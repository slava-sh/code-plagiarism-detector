#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int n, i, j, lol, pop, t, c,c1,c2, a[1001][101], k[10001], col[10001], pos,pos1, pos2,d,i1;
map<int, bool> m;
map<int, int> m1;
string s, x;
bool ok;
bool was[1001][101];
void anss() {
	cout << '+';
	cout << pop;
	cout << "(", cout << lol << ")";
	int t = x.size() - pos2;
	if (t == 4) {
		c = 2;
		c1 = 4;
		for (int lo = pos2; lo < x.size()-1; lo++) {
			cout << x[lo];
			c--;
			c1--;
			if (c == 0)
				cout <<'-';
			if (c1 == 0)
				cout <<'-';
		}
		cout << x[x.size()-1];
	}
	if (t == 5) {
		c = 3;
		c1 = 5;
		for (int lo = pos2; lo < x.size()-1; lo++) {
			cout << x[lo];
			c--;
			c1--;
			if (c == 0)
				cout <<'-';
			if (c1 == 0)
				cout <<'-';
		}
		cout << x[x.size()-1];

	}if (t == 6) {
		c = 2;
		c1 = 4;
		c2 = 6;
		for (int lo = pos2; lo < x.size()-1; lo++) {
			cout << x[lo];
			c--;
			c1--;
			c2--;
			if (c == 0)
				cout <<'-';
			if (c1 == 0)
				cout <<'-';
			if (c2 == 0)
				cout << '-';
		}
		cout << x[x.size()-1];

	}
	if (t == 7) {
		c = 3;
		c1 = 5;
		c2 = 7;
		for (int lo = pos2; lo < x.size()-1; lo++) {
			cout << x[lo];
			c--;
			c1--;
			c2--;
			if (c == 0)
				cout <<'-';
			if (c1 == 0)
				cout <<'-';
			if (c2 == 0)
				cout << '-';
		}
		cout << x[x.size()-1];
	}
		if (t <= 3)
            	for (int lo = pos2; lo < x.size(); lo++)
			cout << x[lo];


    cout << endl;
}
int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> col[i] >> k[i];
		m[col[i]] = true;
		m1[col[i]] = i;
		for (j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			was[i][a[i][j]] = true;
		}
	}
	cin >> d;
	for (i = 1; i <= d; i++) {
		cin >> x;
		pop = 0;
		for (j = 0; j < 3; j++) {
			pop = pop*10 + (x[j] - '0');
			if (pop == 0){
                cout << "Incorrect" << endl;
                break;
            }
			if (m[pop]) {
				pos = m1[pop];
				lol = 0;
				ok =false;
				for (i1 = j + 1; i1 <= j+5; i1++){
					lol = lol * 10 + (x[i1] - '0');
					if (lol == 0)
                        break;
					if (was[pos][lol]) {
						pos1 = j;
						pos2 = i1+1;
						ok = true;
						break;
					}
                    }
					if (ok == true) {
						if (x[pos2] == '0'){
							cout <<"Incorrect"<<endl;
							break;
						} else {
							anss();
						}
					} else {
						cout << "Incorrect" << endl;
						break;
					}
				}
			}
		}

	return 0;
}
