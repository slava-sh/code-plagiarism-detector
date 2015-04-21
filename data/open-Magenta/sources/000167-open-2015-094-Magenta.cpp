#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
#define MOD 1000000007LL
#define P 5
using namespace std;

void check(char x) {
	if (x == 'Y') {
		exit(0);
	}
	if (x == 'E') exit(0);
}

int cnt = 0;

void go(char c) {
	cnt++;
	cout << c << endl;
	cin >> c;
	check(c);
}

int main(void) {
	for (int i = 0; i < 30; ++i) {
		cnt = 0;
		while (cnt < 6000) {
			for (int j = 0; j <= i; ++j) {
				go('L');
			}
			go('U');
		}
	}
}