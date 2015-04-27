#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>
#include <cassert>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 1000000009
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

int n,m;
LL mod;
map<pair<int,pair<int, int > > ,int> dp; //level, 2, 1
char s[505][505];
int col[505];

int getDp(int level, int dua,int satu)
{
	if (level==n)
	{
		if (satu==0 && dua==0) return 1;
		else return 0;
	}
	else
	{
		if (dp.find(MP(level,MP(dua,satu)))!=dp.end()) return dp[MP(level,MP(dua,satu))];
		int &res = dp[MP(level,MP(dua,satu))];
		res = 0;
		
		//2 ke "butuh 2"
		if (dua>=2)
		{
			res += (LL)(dua*(dua-1)/2)*(LL)getDp(level+1,dua-2,satu+2)%mod;
			res %= mod;
		}
		
		//1 ke "butuh 1" , 1 ke "butuh 2"
		if (dua>=1 && satu>=1)
		{
			res += (LL)(dua*satu)*(LL)getDp(level+1,dua-1,satu)%mod;
			res %= mod;
		}
		
		//2 ke "butuh 1"
		if (satu>=2)
		{
			res += (LL)(satu*(satu-1)/2)*(LL)getDp(level+1,dua,satu-2)%mod;
			res %= mod;
		}
		
		return res;
	}
}

int main()
{
	dp.clear();
	
	scanf("%d %d %I64d",&n,&m,&mod);
	
	for (int i=0;i<m;i++) scanf("%s",s[i]);
	
	//clock_t ct = clock();
	int level = m;
	int dua=0,satu=0;
	
	memset(col,0,sizeof(col));
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (s[i][j]=='1') col[j]++;
		}
	}
	
	for (int i=0;i<n;i++)
	{
		if (col[i]==0) dua++;
		else if (col[i]==1) satu++;
	}
	
	printf("%d\n",getDp(level, dua, satu));
//	clock_t ct2 = clock();
//	cout << (double)(ct2-ct)/CLOCKS_PER_SEC << endl;
	
	return 0;
}

