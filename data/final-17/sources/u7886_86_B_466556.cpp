#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

int neigh[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

char a[1010][1010];
int used[20];

int main()
{
	int i,j,m,n,k,l,o,p,x,y,xx,yy,b1,b2;
	vector<pair<int,int> > aa;
	scanf("%d%d",&m,&n);
	for (i=0;i<m;i++)
		scanf("%s",a[i]);
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			if (a[i][j]=='.')
			{
				b1=0;
				if ((i+1<m)&&(a[i+1][j]=='.'))
				{
					a[i][j]='W';
					a[i+1][j]='W';
					aa.clear();
					aa.push_back(make_pair(i,j));
					aa.push_back(make_pair(i+1,j));
					memset(used,0,sizeof(used));
					for (k=0;k<aa.size();k++)
						for (l=0;l<4;l++)
						{
							x=aa[k].first+neigh[l][0];
							y=aa[k].second+neigh[l][1];
							if ((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(a[x][y]>='0')&&(a[x][y]<='9'))
								used[a[x][y]-'0']=1;
							if ((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(a[x][y]=='.'))
							{
								b2=1;
								for (o=0;o<4;o++)
								{
									xx=x+neigh[o][0];
									yy=y+neigh[o][1];
									if ((xx>=0)&&(xx<m)&&(yy>=0)&&(yy<n)&&(a[xx][yy]=='.'))
										b2=0;
								}
								if (b2==1)
								{
									a[x][y]='W';
									aa.push_back(make_pair(x,y));
								}
							}
						}
					for (k=0;k<10;k++)
						if (used[k]==0) break;
					for (l=0;l<aa.size();l++)
						a[aa[l].first][aa[l].second]='0'+k;
					b1=1;
				}
				if ((b1==0)&&(j+1<n)&&(a[i][j+1]=='.'))
				{
					a[i][j]='W';
					a[i][j+1]='W';
					aa.clear();
					aa.push_back(make_pair(i,j));
					aa.push_back(make_pair(i,j+1));
					memset(used,0,sizeof(used));
					for (k=0;k<aa.size();k++)
						for (l=0;l<4;l++)
						{
							x=aa[k].first+neigh[l][0];
							y=aa[k].second+neigh[l][1];
							if ((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(a[x][y]>='0')&&(a[x][y]<='9'))
								used[a[x][y]-'0']=1;
							if ((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(a[x][y]=='.'))
							{
								b2=1;
								for (o=0;o<4;o++)
								{
									xx=x+neigh[o][0];
									yy=y+neigh[o][1];
									if ((xx>=0)&&(xx<m)&&(yy>=0)&&(yy<n)&&(a[xx][yy]=='.'))
										b2=0;
								}
								if (b2==1)
								{
									a[x][y]='W';
									aa.push_back(make_pair(x,y));
								}
							}
						}
					for (k=0;k<10;k++)
						if (used[k]==0) break;
					for (l=0;l<aa.size();l++)
						a[aa[l].first][aa[l].second]='0'+k;
					b1=1;
				}
				if (b1==0)
				{
					printf("-1\n");
					return 0;
				}
			}
	//printf("%d %d\n",m,n);
	for (i=0;i<m;i++)
		printf("%s\n",a[i]);
	return 0;
}

