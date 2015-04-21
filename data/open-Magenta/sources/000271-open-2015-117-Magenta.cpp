#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

int curc,curnum,curgroup,i;
char c[4]={'R','U','L','D'};
char ans;

int main()
{
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	curc=0;
	curnum=1;
	curgroup=1;
	while (1)
	{
		for (i=1; i<=curnum; i++)
		{
			cout<<c[curc]<<endl;
			cout.flush();
			cin>>ans;
			if (ans=='Y' || ans=='E')
			{
				return 0;
			}		
		}
		curgroup++;
		curc++;
		if (curc==4) curc=0;
		if (curgroup==3)
		{
			curgroup=1;
			curnum++;
		}
	}
	return 0;
}



