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
ll a[200500], b[200500];
ll sum[200500];

void go(char c) {
	cout << c << endl;
	cin >> c;
	if (c == 'Y') exit(0);
	if (c == 'E') exit(0);
}

int prim[] = {19, 17, 21, 29, 31};

int main(void) {
	for (int i = 0; i < 6000; ++i) {
		int t = 31;
		for (int i = 0; i < t; ++i)
			go('L');
		for (int i = 0; i < t; ++i)
			go('U');
	}
	exit(1);
	/*for (int i = 0; i < 6000; ++i) {
		int t = 31;
		for (int i = 0; i < t; ++i)
			go('L');
		go('U');
	}*/
}