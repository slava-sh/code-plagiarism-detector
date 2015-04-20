#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

#define TASK "prizes"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ll n,m;
	cin>>n>>m;
	cout<<min((n+2)/4,(m+2)/4);
}