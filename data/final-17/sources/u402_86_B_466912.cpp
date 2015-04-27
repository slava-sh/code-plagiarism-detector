/*
ID: hamed_51
PROG: ?
LANG: C++
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOREACH(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define FOR(i, a, n) for (register int i = (a); i < (int)n; ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define point pair<int, int>
#define ll long long
#define pb push_back
#define error(x) cerr << #x << " = " << x << endl;
#define ull unsigned long long
#define MAXN 100100

vector<string> V;

int main() {
    int n, m;
    cin >> n >> m;
    V.resize(n);
    FOR(i, 0, n) cin >> V[i];
    FOR(i, 0, n) {
        int cnt = 0;
        FOR(j, 0, m) {
            if (V[i][j] == '.') {
                if (j+1 < m && V[i][j+1] == '.') V[i][j] = V[i][j+1] = 3*(i%3)+cnt%3+'0';
                else if (i+1 < n && V[i+1][j] == '.') V[i][j] = V[i+1][j] = 3*(i%3)+cnt%3+'0';
                if (V[i][j] != '.') cnt++;
            }
        }
    }
    FOR(i, 0, n) FOR(j, 0, m) if (V[i][j] == '.') {
        if (i && isdigit(V[i-1][j])) V[i][j] = V[i-1][j]; else
        if (j && isdigit(V[i][j-1])) V[i][j] = V[i][j-1]; else
        if (i+1 < n && isdigit(V[i+1][j])) V[i][j] = V[i+1][j]; else
        if (j+1 < m && isdigit(V[i][j+1])) V[i][j] = V[i][j+1]; else {
            cout << -1 << endl;
            return 0;
        }
    }
    FOR(i, 0, n) cout << V[i] << endl;
	return 0;
}

