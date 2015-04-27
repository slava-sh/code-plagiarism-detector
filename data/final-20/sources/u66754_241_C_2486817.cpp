#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=100+5;
int n,hr,hl;
struct Tm
{
	int v,a,b;
	char c;
};
Tm mir[maxn];
int res=0,tmp_res,p1,p2;
bool tt;
double x,sum;
const double len=100000,hi=100;

bool cmp(Tm q,Tm p)
{
	return q.a<p.a;
}

int max(int a,int b)
{
	if (a>b) return a; else return b;
}

int main()
{
	cin>>hl>>hr>>n;
	for (int i=1;i<=n;i++)
	 cin>>mir[i].v>>mir[i].c>>mir[i].a>>mir[i].b;
	sort(mir+1,mir+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
	if (!(hi==hl || ((i % 1)==1 && hi==hr) || ((i & 1)==0 && hr==0)))
	{
		tmp_res=0;
		if ((i & 1)==1) sum=(hi-hl)+(hi-hr)+(i-1)*hi; else sum=(hi-hl)+hr+(i-1)*hi;
		x=len / sum * (double) (hi-hl);p1=1;p2=1;
		for (int j=1;j<=i;j++)
		{
				if ((j & 1)==1)
				{
					tt=0;
					while (mir[p1].a<=x && p1<=n)
					{
						if (mir[p1].b>=x && mir[p1].c=='T')
						{
							tmp_res+=mir[p1].v;tt=1;
							p1++;break;
						}
						p1++;
					}
					if (!tt) break;
				}
				else
				{
					tt=0;
					while (mir[p2].a<=x && p2<=n)
					{
						if (mir[p2].b>=x && mir[p2].c=='F')
						{
							tmp_res+=mir[p2].v;tt=1;
							p2++;break;
						}
						p2++;
					}
					if (!tt) break;
				}
				x+=len / sum *hi;
		}
		if (tt) res=max(res,tmp_res);
	}
//==================================================
	if (!(hl==0 || ((i & 1)==1 && hr==0) || ((i & 1)==0 && hi==hr)))
	{
		tmp_res=0;
		if ((i & 1)==1) sum=hl+hr+(i-1)*hi; else sum=hl+(hi-hr)+(i-1)*hi;
		x=len / sum * (double) hl;p1=1;p2=1;
		for (int j=1;j<=i;j++)
		{
			if ((j & 1)==1)
			{
				tt=0;
				while (mir[p1].a<=x && p1<=n)
				{
					if (mir[p1].b>=x && mir[p1].c=='F')
					{
						tmp_res+=mir[p1].v;tt=1;
						p1++;break;
					}
					p1++;
				}
				if (!tt) break;
			}
			else
			{
				tt=0;
				while (mir[p2].a<=x && p2<=n)
				{
					if (mir[p2].b>=x && mir[p2].c=='T')
					{
						tmp_res+=mir[p2].v;tt=1;
						p2++;break;
					}
					p2++;
				}
				if (!tt) break;
			}
			x+=len / sum *hi;
		}
		if (tt) res=max(res,tmp_res);
	}
	}
	cout<<res<<endl;
	return 0;
}
