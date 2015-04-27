#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define INF (1<<30)
#define pii pair<int, int>

using namespace std;

struct pq
{
    long long cost, node;
    pq(){;}
    pq(long long n, long long c)
    {
        cost=c, node=n;
    }
    bool operator<(const pq &b)const
    {
        return (cost<b.cost);
    }
};

vector<long long>a, b, c;
priority_queue<pq>Q;
map<long long, int>mp;

int main()
{
    int n, cas=1;
    while(scanf("%d", &n)==1)
    {
        mp.clear();
        int i, j, k, num, nd, cst;
        for(i=0;i<n;i++)
        {
            cin>>num;
            mp[num]++;
        }
        map<long long, int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            nd = it->first, cst = it->second;
            Q.push(pq(nd, cst));
        }
        vector<long long>now; pq U;
        long long anode, acost, bnode, bcost, cnode, ccost;
        while(!Q.empty())
        {
            if(SZ(Q)<3)
                break;
            U = Q.top(); Q.pop();
            anode = U.node, acost = U.cost;
            U = Q.top(); Q.pop();
            bnode = U.node, bcost = U.cost;
            U = Q.top(); Q.pop();
            cnode = U.node, ccost = U.cost;
            now.pb(anode), now.pb(bnode), now.pb(cnode);
//            cout<<anode<<" "<<acost<<" "<<bnode<<" "<<bcost<<" "<<cnode<<" "<<ccost<<endl;
            acost--; bcost--; ccost--;
            if(acost>0)
            {
                U = pq(anode, acost);
                Q.push(U);
            }
            if(bcost>0)
            {
                U = pq(bnode, bcost);
                Q.push(pq(bnode, bcost));
            }
            if(ccost>0)
            {
                U = pq(cnode, ccost);
                Q.push(U);
            }
            sort(&now[0], &now[0]+SZ(now));
            a.pb(now[0]), b.pb(now[1]), c.pb(now[2]);
            now.clear();
        }
        cout<<SZ(c)<<endl;
        for(i=0;i<SZ(c);i++)
            cout<<c[i]<<" "<<b[i]<<" "<<a[i]<<endl;
//        a.clear(); b.clear(); c.clear();
//        while(!Q.empty())
//            Q.pop();
    }
    return 0;
}

