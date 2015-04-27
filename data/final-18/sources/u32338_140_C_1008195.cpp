#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <set>
#include <string>
#include <time.h>
#include <vector>

#define nextLine() {for(int c=getchar(); c!='\n' && c!=EOF; c=getchar());}
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define TASK "file"

using namespace std;

#define pii pair<int,int>
#define mp(x, y) make_pair(x, y)
#define pb(_o_) push_back(_o_)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double ldb;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vb;
typedef vector<vi> vvb;
typedef list<int> li;
typedef multiset<int>::iterator siit;

const int inf = (1 << 30) - 1;
const ldb eps = 1e-9;
const ldb pi = fabs(atan2(0.0, -1.0));


int *ass;
void ML()
{
	for (;;)
	{
		ass = new int[2500000];
		for (int i = 0; i < 2500000; i++)
			ass[i] = rand();
	}
}

void TL()
{
	for(;;);
}

map <int, int> mp;
int n;
multimap<int, int> mp2;

void LoAd()
{
	scanf("%d", &n);
	for (int x, i = 0; i < n; i++)
	{
		scanf("%d", &x);
		mp[x]++;
	}
	map<int, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		mp2.insert(pair<int,int>(it->second,it->first));
		//mp2[2] = 3;
		//mp2[it->second] = it->first;
	}

}

void SoLvE()
{
	multimap<int, int>::iterator it;
	multimap<int, int>::iterator doom[3];

	vvi res;
	bool flag = true;

	for(int j = 0; flag; j++)
	{
		res.push_back(vi());
		it = mp2.end();

		for (int i = 0; i < 3; i++)
		{
			if (it == mp2.begin())
			{
				res.pop_back();
				flag = false;
				break;
			}
			it--;

			res[j].push_back(it->second);
			doom[i] = it;
		}
		if (!flag)
			break;
		for (int i = 0; i < 3; i++)
		{
			if (doom[i]->first != 1)
				mp2.insert(pair<int,int>(doom[i]->first - 1, doom[i]->second));
			mp2.erase(doom[i]);
		}

	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
	{
		sort(res[i].begin(), res[i].end());
		if (res[i][0] == res[i][1] || res[i][0] == res[i][2] || res[i][2] == res[i][1])
			TL();
		for (int j = 2; j >= 0; j--)
			printf("%d ", res[i][j]);
		puts("");
	}
}

int main()
{
	srand( (int) time(NULL));
	//freopen(TASK".in","r",stdin);	freopen(TASK".out","w",stdout);
	LoAd();
	SoLvE();
	return 0;
}