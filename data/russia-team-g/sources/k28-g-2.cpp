#include<cstdlib>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "prizes"

using namespace std;

int n, m, x;
void go()	{
	printf("0");
	exit(0);
}

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf("%d%d", &n, &m);
	if (n + m <= 3) go();
	if (n == 1 || m == 1)	{
		x = n + m - 1;
		cout<<(x - 3) / 4 + 1;
		exit(0);
	}
	if (n == 2 || m == 2) go();
	if (n == 3 || m == 3) 	{
		cout<<1;
		exit(0);
	}
	cout<<2;

	return 0;
}

