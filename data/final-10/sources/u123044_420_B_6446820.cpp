#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

const int maxn = 100005;

int state[maxn],yes[maxn],no[maxn];
int mes[maxn],init[maxn];

int main()
{
    int n,m,a;
    char s[2];
    memset(state,-1,sizeof(state));
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%s%d",s,&a);
        if(s[0]=='+')
        {
            mes[i] = a;
            state[a] = 1;
        }
        else
        {
            mes[i] = -a;
            if(state[a]==-1)
                init[a] = 1;
            state[a] = 0;
        }
    }
    vector<int> fi;
    int siz = 0;
    for(int i=1; i<=n; i++)
    {
        if(init[i]==1)
            siz++;
        if(state[i]==-1)
            yes[i] = 1;
    }
    memset(state,-1,sizeof(state));
    int first = 0;
    for(int i=1; i<=n; i++)
    {
        if(init[i])
            state[i] = 1;
    }
    int cnt = 0,flag=0;
    for(int i=0; i<m; i++)
    {
        if(mes[i]>0)
        {
            int to = mes[i];
            if(siz)
                no[to] = 1;
            else
            {
                first = to;
                fi.push_back(to);
            }
            siz++;
            state[to] = 1;
        }
        else
        {
            int to = -mes[i];
            if(siz>1)
                no[to] = 1;
            else
            {
                if(first)
                {
                    if(to!=first)
                        flag = 1;
                }
                else
                {
                    fi.push_back(to);
                }
            }
            siz--;
            state[to] = 0;
        }
    }
    vector<int> v;
    for(int i=1; i<=n; i++)
        if(yes[i])
            v.push_back(i);
    if(flag||fi.size()==0)
    {
        for(int i=1;i<=n;i++)
            if(init[i]&&no[i]==0)
                v.push_back(i);
        sort(v.begin(),v.end());
        printf("%d\n",v.size());
        for(int i=0; i<v.size(); i++)
            printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    }
    else
    {
        //puts("hello");
        int ho = fi[0],add = 1;
        for(int i=1; i<fi.size(); i++)
            if(fi[i]!=ho)
                add = 0;
        if(no[ho])
            add = 0;
        if(add)
        {
            v.push_back(ho);
            sort(v.begin(),v.end());
        }
        printf("%d\n",v.size());
        for(int i=0; i<v.size(); i++)
            printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    }
}
