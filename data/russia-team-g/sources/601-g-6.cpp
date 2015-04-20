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
	if(n>m)swap(n,m);
	if(n==1)
	{
		cout<<(m+1)/4;
		return 0;
	}
	if(n==2)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
}