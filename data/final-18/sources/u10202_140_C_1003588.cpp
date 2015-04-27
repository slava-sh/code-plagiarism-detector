#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> paii;

#define REP(i,n) for (i=0;i<n;i++)

#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include <conio.h>
//#define wait getch()

struct data
{
    int rad;
    int freq;

    bool operator<(const data & x)const
    {
        return freq<x.freq;
    }
} ;


int main(void)
{
    int n,val;
    map<int,int>M;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        M[val]++;
    }

    int cnt=0;
    priority_queue<data>Q;

    data tmp,node;
    data g1,g2,g3;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
    {
        tmp.rad=it->fs;tmp.freq=it->sc;
        Q.push(tmp);
    }

    vector<int>v[35000];

    int tok=0;
    while(!Q.empty())
    {
        bool fl=1;
        if(!Q.empty()) {g1=Q.top();Q.pop();}
        else break;
        if(!Q.empty()) {g2=Q.top();Q.pop();}
        else break;
        if(!Q.empty()) {g3=Q.top();Q.pop();}
        else break;

        v[tok].pb( g1.rad );
        v[tok].pb( g2.rad );
        v[tok].pb( g3.rad );

        tok++;
        if( g1.freq>1 ) { g1.freq--;Q.push(g1); }
        if( g2.freq>1 ) { g2.freq--;Q.push(g2); }
        if( g3.freq>1 ) { g3.freq--;Q.push(g3); }
    }
    printf("%d\n",tok);
    for(int i=0;i<tok;i++)
    {
        sort( v[i].rbegin(), v[i].rend() );
        deb(v[i][0],v[i][1],v[i][2]);
    }

    return 0;
}

