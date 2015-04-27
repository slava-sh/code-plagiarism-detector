#include  <stdio.h>
#include <string.h>
#include   <math.h>

#include    <queue>
#include <iostream>
#include   <vector>
#include<algorithm>
#include      <map>
#include  <sstream>
#include      <set>
using namespace std;

typedef pair<int , int> pii;


template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

#define     MP(a,b)             make_pair(a,b)
#define     mem(a,b)            memset(a , b , sizeof (a))
#define     ll                  long long
#define     sz(a)               (int)a.size()
#define     llsz(a)             (long long)a.size()
#define     pb(a,b)             a.push_back(b)
#define     c_sq(a)             (int)sqrt(a)
#define     llsq(a)             (long long)sqrt(a)
#define     cl(a)               a.clear()
#define     I_SZ                1000000000000ll
#define     MOD                 100000007
#define     fr                  first
#define     sc                  second
#define     iter(a,b)           for (b=a.begin();b!=a.end();b++)
#define     PI                  2.0*acos(0.0)
#define     all(a)              a.begin(),a.end()
#define     oo                  (1<<30)
#define     popc(a)             __builtin_popcount(a)
#define     lloo 		(1ll<<62)


#define SZ 1000000

struct o_o
{
    int u , cost , p;

    o_o () {}

    o_o(int x , int y,int z) {u = x , cost = y,p=z;}

    bool operator < (const o_o &x) const
    {
        return cost > x.cost;
    }

};

vector < pii > adj[1005];
vector < string > inp[ 1005 ];
int n , m , k , w;

int col[1005] , dis[1005] , par[1005];

int mstMin (void)
{
    priority_queue < o_o > minQ;
    mem (col , -1);
    mem (dis , -1);

    for ( int i=0 ; i<k ; i++ )
    {
        dis[i] = n*m;
        minQ.push (o_o(i , n*m , -1));
    }

    int i;

    while (!minQ.empty())
    {
        o_o tmp = minQ.top();
        minQ.pop();
        int x = tmp.u , cost = tmp.cost;

        if (col[x] == -1)
        {
            par[ x ] = tmp.p;
//            deb ( "HERE : " , x+1 , par[x]+1 );
            for (i=0 ; i<sz(adj[x]) ; i++)
            {
                int v = adj[x][i].fr , cS = adj[x][i].sc;
                if ((dis[v] == -1 || dis[v] > cS) && col[v] == -1)
                {
                    dis[v] = cS;
                    minQ.push (o_o(v,dis[v],x));
                }
            }
            col[x] = 1;
        }
    }

    int path = 0;
    for (i=0 ; i<k ; i++)
    {
        path += dis[i];
    }

    return path;
}

int getDis ( int a , int b )
{
    int res = 0;
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<m ; j++ )
            res += w * ( inp[a][i][j] != inp[b][i][j] );
    }
    return res;
}

int main ( void )
{
    for ( int i=0 ; i<1005 ; i++ )
    {
        cl ( adj[i] );
        cl ( inp[i] );
    }


    scanf ("%d %d %d %d",&n,&m,&k,&w);

    for ( int i=0 ; i<k ; i++ )
    {
        string s;
        for ( int j=0 ; j<n ; j++ )
        {
            cin >> s;
            pb ( inp[i] , s );
        }
    }

    for ( int i=0 ; i<k ; i++ )
    {
        for ( int j=i+1 ; j<k ; j++ )
        {
            int val = getDis ( i , j );
//            deb ( i , j , val );
            pb ( adj[ i ] , MP( j , val ) );
            pb ( adj[ j ] , MP( i , val ) );
        }
    }

    int val = mstMin();
    deb ( val );
    mem ( col , 0 );
    col[ 0 ] = 1;

//    for ( int i=0 ; i<k ;  i++ )
//    {
//        deb ( i , par[i] );
//    }

    printf ("%d %d\n",1,0);
    for ( int i=1 ; i<k ; i++ )
    {
        if ( par[ i ] == -1 )
        {
            printf ("%d %d\n",i+1,par[i]+1);
            col[ i ] = true;
        }
    }
    while ( true )
    {
        bool flag = true;
        for ( int i=0 ; i<k ; i++ )
        {
            if ( col[ i ] ) continue;
            if ( col[ par[ i ] ] )
            {
                printf ("%d %d\n",i+1,par[i]+1);
                col[ i ] = true;
                flag = false;
                break;
            }
        }
        if ( flag ) break;
    }


    return 0;
}
