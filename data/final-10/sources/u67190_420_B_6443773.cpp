#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define F cin
#define G cout

//#define LOCAL

const int N = 100010;

vector< pair<int,int> > log;
int n,m,ok[N],aib[N];

int bit(int x)
{
    return x & (-x);
}

void add(int x,int v)
{
    for (int i=x;i<=n;i+=bit(i))
        aib[i] += v;
}

int query(int x)
{
    int out = 0;
    for (int i=x;i>0;i-=bit(i))
        out += aib[i];
    return out;
}

void solve()
{
    int last = 0;
    for (int i=0;i<m;++i)
    {
        int x = log[i].first;
        int y = log[i].second;
        if ( y == 0 )
        {
            if ( query(n) != 0 ) ok[x] = 0;
            add(x,1);
        }
        if ( y == 1 )
        {
            if ( query(x) - query(x-1) == 0 )
            {
                for (int j=last;j<i;++j)
                    //if ( log[j].second == 0 )
                        ok[ log[j].first ] = 0;
                last = i;
            }
            else
                add(x,-1);
            if ( query(n) != 0 ) ok[x] = 0;
            if ( i+1 < m )
                if ( log[i+1].first != x )
                    ok[x] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    #ifdef LOCAL
        ifstream F("p.in");
        ofstream G("p.out");
    #endif

    F>>n>>m;
    for (int i=1;i<=n;++i)
        ok[i] = 1;
    for (int i=1;i<=m;++i)
    {
        char ch;int x;
        F>>ch;
        F>>x;
        if ( ch == '+' )
            log.push_back( make_pair( x , 0 ) );
        else
            log.push_back( make_pair( x , 1 ) );
    }
    solve();
    for (int i=0;i<m;++i) log[i].second = 1-log[i].second;
    reverse(log.begin(),log.end());
    memset(aib,0,sizeof(aib));
    solve();
    vector<int> ans;
    for (int i=1;i<=n;++i)
        if ( ok[i] == 1 )
            ans.push_back(i);
    G<<ans.size()<<'\n';
    for (size_t i=0;i<ans.size();++i)
        G<<ans[i]<<' ';
}
