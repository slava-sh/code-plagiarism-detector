/* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef pair<int ,int > pii;
typedef  long long ll;
const int  MAXN = 100000+10;
map<pii , int>m;
vector<int >G[3*MAXN],v;

int te[3*MAXN];
ll ans=0;
int  main()
{
   ios_base::sync_with_stdio(false);
        ll n,p;
        cin>>n>>p;
       
        for(int i=1;i<=n;i++)
        {
                ll a, b;
                cin>>a>>b;
                        if(a>b)
                         swap(a,b);
               te[a]++;
               te[b]++;
               m[pii(a,b)]++;
                if(m[pii(a,b)]==1)
                {
                        G[a].push_back(b);
                         G[b].push_back(a);
                }
        }
        if(p==0)
        {
                cout<<n*(n-1)/2;
                return 0;
        }
   
        for(int i=1;i<=n;i++)
                          v.push_back(te[i]);    
       sort(v.begin() , v.end());
        for(int i=1;i<=n;i++)
        {
                        int q= lower_bound(v.begin() , v.end() , p-te[i] )-v.begin();
                        ans+=n-q;
                       if(te[i]>=p-te[i])
                        ans--;
                for(int j=0;j<G[i].size();j++)
                    if(te[i]+ te[G[i][j]]>=p &&(te[i] + te[G[i][j]] - m[pii(min(i , G[i][j]) , max(i,G[i][j])) ] )<p)
                     ans--;                
        
        }
        cout<<ans/2;
     
} 
