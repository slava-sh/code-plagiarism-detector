#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 120000;

int nowx[MAXN];
int nowy[MAXN];

int main() {
	for (int i = 0; i < MAXN; ++i)
		nowx[i] = 0;
	for (int i = 0; i < MAXN; ++i)
		nowy[i] = 0;
	nowx[0] = 1;
	nowy[0] = 1;
	int x = 0;
	int y = 0;
	int nn = 2;
	cout << "U\n";
	cout.flush();
	++x;
	nowy[0] = 2;
	nowx[1] = 1;
	char c;
	cin >> c;
	if (c != 'N')
		return 0;
	while (true) {
		nn = nn * 1.5;
	//	cout << nn << "\n";
		if (x == 0) {
			while (x + 2 <= nn) {
				int k = nn / (x + 2) - 1;
				while (y != k) {
					if (y < k) {
						++y;
						cout << "R\n";
						cout.flush();
						char c;
						cin >> c;
						if (c != 'N')
							return 0;
						nowx[x] = max(nowx[x], y + 1);
					}
					else {
						--y;
						cout << "L\n";
						cout.flush();
						char c;
						cin >> c;
						if (c != 'N')
							return 0;
					}
				}
				++x;
				cout << "U\n";
				cout.flush();
				char c;
				cin >> c;
				if (c != 'N')
					return 0;
				int lst = nowx[x];
				nowx[x] = max(nowx[x], y + 1);
				nowy[y] = max(nowy[y], x + 1);
				while (y > lst) {
					--y;
					cout << "L\n";
					cout.flush();
					char c;
					cin >> c;
					if (c != 'N')
						return 0;
					nowy[y] = max(nowy[y], x + 1);
				}
			}
		}
		else {
			while (y + 2 <= nn) {
				int k = nn / (y + 2) - 1;
				while (x != k) {
					if (x < k) {
						++x;
						cout << "U\n";
						cout.flush();
						char c;
						cin >> c;
						if (c != 'N')
							return 0;
						nowy[y] = max(nowy[y], x + 1);
					}
					else {
						--x;
						cout << "D\n";
						cout.flush();
						char c;
						cin >> c;
						if (c != 'N')
							return 0;
					}
				}
				++y;
				cout << "R\n";
				cout.flush();
				char c;
				cin >> c;
				if (c != 'N')
					return 0;
				int lst = nowy[y];
				nowy[y] = max(nowy[y], x + 1);
				nowx[x] = max(nowx[x], y + 1);
				while (x > lst) {
					--x;
					cout << "D\n";
					cout.flush();
					char c;
					cin >> c;
					if (c != 'N')
						return 0;
					nowx[x] = max(nowx[x], y + 1);
				}
			}
		}
	}
	return 0;
}

