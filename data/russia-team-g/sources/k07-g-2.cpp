#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <algorithm>
//#include <>

using namespace std;
#define fname "prizes"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

int n,m;

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> m ;
	if(m==1){
		cout<<(n+1)/4;
		return 0;
	}
	if(n==1){
		cout<<(m+1)/4;
		return 0;
	}
	if (n==2 || m==2)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
