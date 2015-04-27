#pragma comment (linker, "/STACK:16777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <numeric>
#include <complex>
#include <string>
#ifdef IGEL_ACM
#include <ctime>
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pnt;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector <vector < pair <int, int> > > VVP;

#define FI(i,a) for (int i=0; i<(a); ++i)
#define RFI(i,a) for (int i=(a); i>=0; --i)
#define FOR(i,s,e) for (int i=(s); i<(e); ++i)
#define RFOR(i,e,s) for (int i=(e); i>=s; --i)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define ISIN(s,a) (s.find(a)!=s.end())
#define sqr(a) ((a)*(a))
#define CPY(a, b) memcpy(a, b, sizeof(a))

#define dout(a) cerr << a << endl
#define sout(a) cerr << a << "  "


const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;
//*
char ch_ch_ch[1<<20];
string gs() {scanf("%s",ch_ch_ch); return string(ch_ch_ch);}
string gl() {gets(ch_ch_ch); return string(ch_ch_ch);}
//*/

map <int, int> c;
set <pnt> s;
VI q1,q2,q3;

void solution()
{     
    int n;
    cin >> n;
    FI(i,n)
    {
        int a;
        scanf("%d",&a);
        c[a]++;
    }
    for (map <int, int>::iterator it=c.begin(); it!=c.end(); ++it)
        s.insert(mp(-it->second,it->first));
    int cnt=0;
    while (s.size()>=3)
    {
        set <pnt>::iterator it=s.begin();
        pnt x1=*it;
        q1.pb(it->second);
        ++it;
        q2.pb(it->second);
        pnt x2=*it;
        ++it;
        q3.pb(it->second);
        pnt x3=*it;
        s.erase(x1);
        if (++x1.first<0) s.insert(x1);
        s.erase(x2);
        if (++x2.first<0) s.insert(x2);
        s.erase(x3);
        if (++x3.first<0) s.insert(x3);
    }
    printf("%d\n",q1.size());
    FI(i,q1.size()) 
    {
        int q[3]={q1[i],q2[i],q3[i]};
        sort(q,q+3);
        printf("%d %d %d\n",q[2],q[1],q[0]);
    }
}




int main(int argc, char** argv)
{
    
       
#ifdef IGEL_ACM
        freopen("sample.in","r",stdin);
	//freopen("sample.in", "w", stdout);
	clock_t beg_time = clock();
#else
        //freopen(argv[1],"r",stdin);
	//freopen("drawing.dat", "r", stdin);
	//freopen("drawing.sol", "w", stdout);
#endif
        
        solution(); 


#ifdef IGEL_ACM
	fprintf(stderr,"Time: %.3lf\n",1.0*(clock()-beg_time)/CLOCKS_PER_SEC);
#endif

    return 0;
}