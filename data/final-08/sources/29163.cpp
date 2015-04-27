#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define endl ('\n')

const int inf=1999999999;
const double pi=acos(-1.0);
const double eps=1e-10;
char gc(){char c;while(isspace(c=getchar()));return c;}
int gs(char* s){gets(s);int l=strlen(s);while(l && isspace(s[l-1]))s[--l]=0;return l;}

int n;
double p[101];
double isok(double a)
{
	double tmn=1e20,tmx=-1e20;
	for(int i=0;i<=n;i++)
	{
		if(i*2>n)
			tmx=max(tmx,(p[i]-a)/(i-n/2.));
		if(i*2<n)
			tmn=min(tmn,(a-p[i])/(n/2.-i));
	}
//	cout<<a<<' '<<tmn<<' '<<tmx<<endl;
	return tmn<tmx;
}
int main()
{
//	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
//	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%lf",&p[i]);
	double low=-0.001,mid,high=1.001;
	if((n%2)==0)
		low=p[n/2];
	for(int i=0;i<60;i++)
	{
		mid=(low+high)/2;
		if(isok(mid))
			low=mid;
		else
			high=mid;
	}
	printf("%.10f\n",(low+high)/2);
	return 0;
}
