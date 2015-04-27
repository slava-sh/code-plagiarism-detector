//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <time.h>
#include <sstream>
#include <fstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000000
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define eps 1e-5
#define X first
#define Y second

int n, k;
string s1, s2;
LL is1[200000][26];																																										LL p = 1, d = 3;
LL is2[200000][26];
LL W[26], mas[26];
LL D[26];
vector<int> ans;

int main()
{
	cin>>n>>k>>s1>>s2;
	
	For(i,0,n)
	{
		is1[i][s1[i]-'a'] = p;
		if (k>i) is2[i][s2[i]-'a'] = p;
		p*=d;
	}

	For(i,0,k)
		For(j,0,26)
		{
			W[j]+=is1[i][j];
			D[j]+=is2[i][j];
		}

	For(step, 0, n-k+1)
	{
		memset(mas,0,sizeof(mas));
		bool ok=true;
		For(i,0,26)
		if (!mas[i])
		{
			if (W[i]==D[i]) continue;
			For(j,i+1,26)
				if (W[i]==D[j] && W[j]==D[i])
				{
					mas[j]=true;
					goto off;
				}
			ok=false;
			off:;
		}
		if (ok) 
			ans.PB(step+1);
		if (step!=n-k)
		{
			For(i,0,26) 
			{
				D[i]*=d;
				W[i]+=is1[k+step][i]-is1[step][i];
			}
		}
	}

	cout<<ans.size()<<endl;
	For(i,0,ans.size())
		cout<<ans[i]<<" ";
}