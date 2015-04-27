#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);


typedef long long LL;


#define N 1000001
int tree[N+10];


int get(int pos)
{
    int ret=0,i;
    pos++;
    for(i=pos; i>0; i-=(i & -i )) ret+=tree[i];
    return ret;
}




void update(int pos,int val)
{
    int i;
    pos++;


    for(i=pos; i<=N; i+=(i & -i )) tree[i]+=val;
}




//i re sondeho kore k k
vector<int> adj[N+10];


pair<int,int> son[N+10];



//ith pola re sondeho kroe koyjon
int cnt[N+10];




void red(int id)
{
    update(cnt[id],-1);
    cnt[id]--;
    update(cnt[id],1);
}

void inc(int id)
{
    update(cnt[id],-1);
    cnt[id]++;
    update(cnt[id],+1);
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,p,i,j,v,temp;
    scanf("%d %d",&n,&p);




    for(i=0;i<n;i++)
    {
        scanf("%d %d",&son[i].first,&son[i].second);
        son[i].first--;
        son[i].second--;

        adj[son[i].first].push_back(i);
        adj[son[i].second].push_back(i);

        cnt[son[i].first]++;
        cnt[son[i].second]++;
    }


    for(i=0;i<n;i++) update(cnt[i],1);



    LL ans=0;
    for(i=0;i<n;i++)
    {
        int tar=max(p-cnt[i],0);


        for(j=0;j<adj[i].size();j++)
        {
            v=adj[i][j];

            red(son[v].first);
            red(son[v].second);
        }


        temp=get(N-3)-get(tar-1);



        //cout<<temp<<endl;


        ans+=temp;
        for(j=0;j<adj[i].size();j++)
        {
            v=adj[i][j];

            inc(son[v].first);
            inc(son[v].second);
        }

        if(tar==0) ans--;
    }




    printf("%I64d\n",ans/2);
    return 0;
}
