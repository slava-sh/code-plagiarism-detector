#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define sz(a) (int)a.size()

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;
typedef pair <ll, int> li;
typedef pair <int, ll> il;
typedef pair <ll, ll> lll;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef double db;
typedef long double ldb;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef set <int> si;
typedef set <ii> sii;
typedef set <ll> sl;
typedef set <lll> sll;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef vector <si> vsi;

const int N = (int)2e5 + 4;
const int M = (int)2e6 + 100;
const ll inf = (ll)1e9 + 7;
const ldb eps = 1e-10;

map <int, char> m;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int s = 1;
	int k = 0;
	int p = 0;
	int d = 0;
	m[0] = 'R';
	m[1] = 'D';
	m[2] = 'L';
	m[3] = 'U';
	for (; ;)
	{
		cout << m[d % 4] << '\n';
		fflush(stdout);
		++k;
		if (k == s)
		{
			k = 0;
			++d;
			++p;
			if (p % 2 == 0)
				s++;
		}
		char c;
		cin >> c;
		if (c == 'E')
			return 0;
		if (c == 'Y')
			return 0;
	}
	return 0;
}