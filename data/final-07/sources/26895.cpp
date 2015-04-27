// --- BBG v1.1 ---
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
//
using namespace std;
//
//#define ONLINE_JUDGE BOBOGEI
#ifdef ONLINE_JUDGE
#define PP ;
#else
#define PP system("pause");
#endif
#define _I64 long long
#define PI 3.1415926535
#define REP(n,i) for(int (i)=0;(i)<(n);(i)++)
#define CDREP(n,i) for(int (i)=(n)-1;(i)>=0;(i)--)
#define SZ(n) memset((n),0,sizeof(n))
#define SMO(n) memset((n),-1,sizeof(n))
//
int N;
vector<pair<int,int> >pl;
vector<pair<int,int> >ans;
int temp[12345];
//
void dv(int l,int r)
{
    if(l>=r-1)
    {
        return;
    }
    int mid=(l+r)/2;
    dv(l,mid);
    dv(mid,r);
    SZ(temp);
    int ux=pl[mid].first,id=0;
    for(int i=l;i<r;i++)
    {
        ans.push_back(make_pair(ux,pl[i].second));
        //printf("%d,%d\n",ux,pl[i].second);
    }
    //system("pause");
}
//
int main()
{
    scanf("%d",&N);
    int tx,ty;
    if(N==1)
    {
        scanf("%d%d",&tx,&ty);
        printf("2\n%d %d\n28825252 %d\n",tx,ty,ty);
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&tx,&ty);
        pl.push_back(make_pair(tx,ty));
        ans.push_back(pl[i]);
    }
    sort(pl.begin(),pl.end());
    dv(0,N);
    sort(ans.begin(),ans.end());
    int ansn=1;
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i]!=ans[i-1])
        {
            ansn++;
        }
    }
    printf("%d\n",ansn);
    printf("%d %d\n",ans[0].first,ans[0].second);
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i]!=ans[i-1])
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
}
