//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double
#define NAME ""

const ll mod7 = 1000000007;

int op[1000000];
int en[1000000];
bool good[1000000];
bool g2[1000000];
int f[1000000];
int main()
{
    //freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);
   
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        f[i] =  en[i] = m;
    }
    int cnt = 0,L=0;
    for(int i=1;i<=m;++i)
    {
        char ch; int num;
        scanf("%c",&ch);
        scanf("%c %d",&ch,&num);
        if(ch=='+')
        {
            f[num] = min(f[num],i);
            ++cnt;
            good[num] = true;
            if(en[num]==i-1 && cnt==1)
            {
                en[num] = m;
            }
            else
                op[num] = i;
        }
        else
        {
            f[num] = min(f[num],i);
            if(good[num])
            {
                good[num] = false;
                --cnt;
            }
            else 
               L = i;
            if(cnt!=0)
            {
                g2[num] = true;
            }
            en[num] = min(i,en[num]);
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;++i)
    {
        if((op[i]==0 && en[i]==m+1) || (!g2[i] && op[i]<=1 && en[i]==m && f[i]>=L))
        {
            ans.push_back(i);
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    return 0;
}