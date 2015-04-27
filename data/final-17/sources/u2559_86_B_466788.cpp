// topcoder.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <assert.h>
#include <iomanip>
#include <bitset>
#include <time.h>

using namespace std;
typedef long long ll;

static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }	
#define PI	(2.0*acos(0.0))
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define NG (-1)
#define SZ(a) ((int)a.size()) 

#define BIG (987654321)

#if 1

int main()
{
	// ���I ��o�O�ɏ����I
//	freopen("input.txt","r",stdin);

	int H,W;
	scanf("%d %d",&H,&W);

	vector <string> vs;

	for(int y=0;y<H;y++)
	{
		char str[10000];
		scanf("%s",str);

/*
		for(int x=0;x<W;x++)
		{
			if(rand()%2)
			{
				str[x]='#';
			}
			else
			{
				str[x]='.';
			}
		}
		str[W]='\0';
*/
		vs.push_back(string(str));
	}
	

	for(int y=0;y<H;y++)
	{
		int digitx = 0;
		int digity = (y%3)*3;
		for(int x=0;x<W;x++)
		{
			if(vs[y][x]=='.')
			{
				if(INRANGE(x+1,0,W-1)&&vs[y][x+1]=='.')
				{
					char digit = '0'+digitx+digity;
					vs[y][x]=digit;
					vs[y][x+1]=digit;
					digitx = (digitx+1)%3;
				}
				else if (INRANGE(y+1,0,H-1)&&vs[y+1][x]=='.')
				{
					char digit = '0'+digitx+digity;
					vs[y][x]=digit;
					vs[y+1][x]=digit;
					digitx = (digitx+1)%3;
				}
			}
		}
	}

	for(int y=0;y<H;y++)
	{
		for(int x=0;x<W;x++)
		{
			if(vs[y][x]=='.')
			{
				int dx[]={  0,-1,  0,+1};
				int dy[]={ -1, 0, +1, 0};
				for(int d=0;d<4;d++)
				{
					const int nx = dx[d]+x;
					const int ny = dy[d]+y;
					if(INRANGE(nx,0,W-1)&&INRANGE(ny,0,H-1)&&INRANGE(vs[ny][nx],'0','9'))
					{
						vs[y][x]=vs[ny][nx];
					}
				}
			}
		}
	}

	bool ok = true;
	for(int y=0;y<SZ(vs);y++)
	{
		for(int x=0;x<SZ(vs[y]);x++)
		{
			if(vs[y][x]=='.')
			{
				ok = false;
				break;
			}
		}
	}

	if(ok)
	{
		for(int y=0;y<H;y++)
		{
			puts(vs[y].c_str());
		}
	}
	else
	{
		printf("-1");
	}
}





#else
ll get(ll tmp)
{
	ll a = 0;
	ll b = 0;
	ll base = 1;

	while(tmp)
	{
		a += base*(tmp%10);
		b += base*(9-(tmp%10));
		tmp/=10;
		base*=10;
	}
	ll c = a*b;

	return c;
}

int main()
{
	// ���I ��o�O�ɏ����I
//	freopen("input.txt","r",stdin);

	int tmp1,tmp2;
	scanf("%d %d ",&tmp1,&tmp2);
	ll l = tmp1, r = tmp2;

	vector <ll> res;
	res.push_back(get(l));
	res.push_back(get(r));

	for(ll i=5;i<=r;i*=10)
	{
		if(INRANGE(i,l,r))
		{
			res.push_back(get(i));
		}
	}
	sort(res.rbegin(),res.rend());
	cout << res[0] << endl;

#if 0
	for(int i=l;i<=r;i++)
	{
		ll tmp=i;
		ll a = 0;
		ll b = 0;
		ll base = 1;
		while(tmp)
		{
			a += base*(tmp%10);
			b += base*(9-(tmp%10));
			tmp/=10;
			base*=10;
		}
		ll c = a*b;
		cout << " i=" << i << " a=" << a << " b=" << b << " c=" << c << endl;
	
	}
#endif
}

#endif