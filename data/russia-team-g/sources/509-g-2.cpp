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
	if(min(m,n)==1)
	{
		cout << (max(m,n)+1)/4;
		return 0;
	}
	cout << (min(m,n)+1)/4;
	return 0;
}

