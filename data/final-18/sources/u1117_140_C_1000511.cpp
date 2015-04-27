//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define RESET(c,x) memset(c,x,sizeof(c))
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

#define REP(i,a) for(int i = 0; i < (a); i++)

#define sqr(x) ((x)*(x))
#define oo 1000000009

using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
string convertToString(long long a) {
    string res = ""; if (!a) return "0";
    while (a) { res = (char)(a % 10 + 48) + res;  a /= 10; }
    return res;
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}

//newstate = (newstate-1) & oldstate
/**************************CODE HERE*****************************/

void OPEN() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}

int ntest;

map<int,int> Map;
set< pair<int,int> > se;

vector< vector<int> > list;
int n;
int main() {
//    OPEN();
    scanf("%d",&n);
    int u;
    FOR(i,1,n) {
        scanf("%d",&u);
        Map[u]++;
    }
    for(map<int,int>::iterator tmp = Map.begin(); tmp != Map.end(); tmp++) {
        se.insert( make_pair(-tmp->second,tmp->first) );
    }
    while (se.size() >= 3) {
        set< pair<int,int> > ::iterator tmp = se.begin();
        set< pair<int,int> > ::iterator tmp2 = tmp;
        set< pair<int,int> > ::iterator tmp3 = tmp;
        tmp2++; tmp3++; tmp3++;
        
        vector<int> res(0);
        res.push_back( (*tmp).second);
        res.push_back( (*tmp2).second);
        res.push_back( (*tmp3).second);
        sort(res.begin(),res.end());
        list.push_back(res);
        //update
        int u = tmp->first, v = tmp->second;
        u++;
        se.erase(tmp);
        if (u != 0) se.insert( make_pair(u,v));
        
        u = tmp2->first, v = tmp2->second;
        u++;
        se.erase(tmp2);
        if (u != 0) se.insert( make_pair(u,v));
        
        u = tmp3->first, v = tmp3->second;
        u++;
        se.erase(tmp3);
        if (u != 0) se.insert( make_pair(u,v));
        
        
    }
    cout << list.size() << endl;
    FR(i,list.size()) printf("%d %d %d\n",list[i][2],list[i][1],list[i][0]);
    return 0;
}
