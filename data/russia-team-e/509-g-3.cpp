// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int a[1001];

int main()
{
	freopen("prizes.in","r",stdin);
	freopen("prizes.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(min(n,m)==1)
	{
		cout << (max(n,m)+1)/4;
		return 0;
	}
	if(min(n,m)>2)
		cout << 1;
	else 
		cout << 0;
	return 0;
}

