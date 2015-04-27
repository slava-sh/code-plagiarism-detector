#pragma comment(linker,"/stack:67108864")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <climits>
#include <cfloat>
#include <functional>
#include <ctime>
#include <numeric>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>
#include <bitset>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <typeinfo>
#include <cassert>
#include <ctime>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forn1(i,n) for(int i=1;i<=int(n);++i)
#define ford(i,n) for(int i=int(n)-1;i>=0;--i)
#define ford1(i,n) for(int i=int(n);i>0;--i)
#define foran(i,l,r) for(int i=int(l);i<int(r);++i)

#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define all(v) (v).begin(),(v).end()

typedef long double ld;
typedef long long ll;

const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;

const ll INF=1000*1000*1000;
vector <pair <int, int> > a, b;

struct ms{
    int first, second, third;
};

bool good(int c)
{
    int idx = c;
    vector <int> p(c);
    forn(i, c) p[i] = a[i].first;
    for(int j = 0; j < c && idx < a.size(); idx++)
    {
        if(p[j] != a[idx].first) 
        {           
            p[j] = a[idx].first;
            j++;
        }
    }
    for(int j = 0; j < c && idx < a.size(); idx++)
    {
        if (p[j] != a[idx].first) 
        {           
            p[j] = a[idx].first;
            j++;
        }
    }
    if (idx == a.size()) return false;
    else return true;
}

void print(int c)
{
    int idx = c;
    vector <ms> p(c);
    forn(i, c) p[i].first = a[i].second;
    for(int j = 0; j < c && idx < a.size(); idx++)
    {
        if(b[p[j].first].first != a[idx].first) 
        {           
            p[j].second = a[idx].second;
            j++;
        }
    }
    for(int j = 0; j < c && idx < a.size(); idx++)
    {
        if (b[p[j].second].first != a[idx].first) 
        {           
            p[j].third = a[idx].second;
            j++;
        }
    }
    cout <<c <<endl;
    forn(i, c)
    {
        printf("%d %d %d\n", b[p[i].first].first, b[p[i].second].first, b[p[i].third].first);
    }
}

int main()
{
    ifstream ifile("input.txt");
    if (ifile) {
        freopen("input.txt", "rt", stdin);
    }
#ifdef ONLINE_JUDGE
    if (ifile) {
        freopen("output.txt","wt",stdout);
    }
#endif
    int n;
    while(cin >>n)
    {
        a.resize(n);
        forn(i, n)
        {
            scanf("%d",&a[i].first);
            a[i].second = i;
        }
        a.push_back(mp(-1, -1));
        b = a;
        sort(all(a));
        reverse(all(a));
        int lf = 0, rg = n/3;
        while (rg - lf > 1)
        {
            int mid = ((lf + rg)>>1);
            if (good(mid))
                lf = mid;
            else rg = mid;
        }
        if(good(rg)) lf = rg;
        print(lf);
    }
    return 0;
}