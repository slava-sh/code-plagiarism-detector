#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
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

#define _int64 long long

struct rec
{
  int l,r;
  int s;
  char c;
};

rec a[200];
int used[200];

int main()
{
  char s[100];
  int h1,h2,n;
  _int64 i,j,k,xx1,xx2,x1,y1,x2,y2,b1,b2,tot,best;
  scanf("%d%d%d",&h1,&h2,&n);
  for (i=0;i<n;i++)
  {
    scanf("%d",&a[i].s);
    scanf("%s",s);
    a[i].c=s[0];
    scanf("%d%d",&a[i].l,&a[i].r);
  }
  best=0;
  for (i=-100;i<=100;i++)
  {
    b1=1;
    x1=0;
    y1=h1;
    x2=100000;
    if (i%2==0)
      y2=h2+i*100;
    else y2=(i+1)*100-h2;
    memset(used,0,sizeof(used));
    tot=0;
    for (j=-100;j<=100;j++)
      if ((j*100-y1)*(j*100-y2)<0)
      {
        xx1=abs(j*100-y1)*100000;
        xx2=abs(y1-y2);
        b2=0;
        for (k=0;k<n;k++)
          if (((j%2==0)&&(a[k].c=='F'))||((j%2!=0)&&(a[k].c=='T')))
          {
            if ((a[k].l*xx2<=xx1)&&(xx1<=a[k].r*xx2))
            {
              if (used[k]==0)
              {
                used[k]=1;
                tot+=a[k].s;
                b2=1;
              }
              else b1=0;
            }
          }
        if (b2==0) b1=0;
      }
    if ((b1==1)&&(tot>best)) best=tot;
  }
  printf("%d\n",(int)best);
}
